#include "HUDDrawer.hpp"

#include <ai/PlayerController.hpp>
#include <data/WeaponData.hpp>
#include <engine/GameData.hpp>
#include <engine/GameState.hpp>
#include <engine/GameWorld.hpp>
#include <engine/ScreenText.hpp>
#include <objects/CharacterObject.hpp>
#include <render/GameRenderer.hpp>

#include <glm/gtc/constants.hpp>
#include <glm/gtc/quaternion.hpp>

#include <iomanip>
#include <sstream>

void HUDDrawer::drawScriptTimer(GameWorld* world, GameRenderer& render) {
    if (world->state->scriptTimerVariable) {
        const glm::ivec2 vp = render.getLogicalSize();
        float scriptTimerTextX = static_cast<float>(
            vp.x -
            hudParameters.uiOuterMargin * designScale);
        float scriptTimerTextY =
            hudParameters.uiScriptTimerHeight * designScale;

        TextRenderer::TextInfo ti;
        ti.font = FONT_PRICEDOWN;
        ti.size = hudParameters.uiTextSize * designScale;
        ti.align = TextRenderer::TextInfo::TextAlignment::Right;

        {
            int32_t seconds = *world->state->scriptTimerVariable / 1000;
            std::stringstream ss;
            ss << std::setw(2) << std::setfill('0') << seconds / 60
               << std::setw(0) << ":" << std::setw(2) << seconds % 60;

            ti.text = GameStringUtil::fromString(ss.str(), ti.font);
        }

        ti.baseColour = hudParameters.uiShadowColour;
        ti.screenPosition =
            glm::vec2(scriptTimerTextX + 1.f, scriptTimerTextY + 1.f);
        render.text.renderText(ti);

        ti.baseColour = hudParameters.uiScriptTimerColour;
        ti.screenPosition = glm::vec2(scriptTimerTextX, scriptTimerTextY);
        render.text.renderText(ti);
    }
}

void HUDDrawer::drawMap(ViewCamera& currentView, ai::PlayerController* player,
                        GameWorld* world, GameRenderer& render) {
    MapRenderer::MapInfo map;

    if (world->state->hudFlash != HudFlash::FlashRadar ||
        std::fmod(world->getGameTime(), 0.5f) >= .25f) {
        glm::quat camRot = currentView.rotation;

        map.rotation = glm::roll(camRot) - glm::half_pi<float>();
        map.worldSize = hudParameters.uiWorldSizeMin;
        map.worldSize = hudParameters.uiWorldSizeMax;
        if (player) {
            map.worldCenter = glm::vec2(player->getCharacter()->getPosition());
        }

        const glm::ivec2& vp = render.getLogicalSize();

        const float margin = hudParameters.uiOuterMargin * designScale;
        const float mapSize = hudParameters.uiMapSize * designScale;
        glm::vec2 mapTop = glm::vec2(margin, vp.y - (margin + mapSize));
        glm::vec2 mapBottom = glm::vec2(margin + mapSize, vp.y - margin);

        map.screenPosition = (mapTop + mapBottom) / 2.f;
        map.screenSize = mapSize * 0.95f;

        render.map.draw(world, map);
    }
}

void HUDDrawer::drawPlayerInfo(ai::PlayerController* player, GameWorld* world,
                               GameRenderer& render) {
    const glm::ivec2 vp = render.getLogicalSize();
    const float margin = hudParameters.uiOuterMargin * designScale;
    const float weaponSize = hudParameters.uiWeaponSize * designScale;
    const float infoMargin = hudParameters.uiInfoMargin * designScale;
    const float textHeight = hudParameters.uiTextHeight * designScale;
    float infoTextX = static_cast<float>(vp.x -
                      (margin + weaponSize + infoMargin));
    float infoTextY = 0.f + margin;
    float iconX = static_cast<float>(vp.x -
                  (margin + weaponSize));
    float iconY = margin;
    float wantedX = static_cast<float>(vp.x - margin);
    float wantedY = hudParameters.uiWantedLevelHeight * designScale;

    TextRenderer::TextInfo ti;
    ti.font = FONT_PRICEDOWN;
    ti.size = hudParameters.uiTextSize * designScale;
    ti.align = TextRenderer::TextInfo::TextAlignment::Right;

    {
        std::stringstream ss;
        ss << std::setw(2) << std::setfill('0') << world->getHour()
           << std::setw(0) << ":" << std::setw(2) << world->getMinute();

        ti.text = GameStringUtil::fromString(ss.str(), ti.font);
    }

    ti.baseColour = hudParameters.uiShadowColour;
    ti.screenPosition = glm::vec2(infoTextX + 1.f, infoTextY + 1.f);
    render.text.renderText(ti);

    ti.baseColour = hudParameters.uiTimeColour;
    ti.screenPosition = glm::vec2(infoTextX, infoTextY);

    render.text.renderText(ti);

    infoTextY += textHeight;

    {
        std::stringstream ss;
        ss << std::setw(8) << std::setfill('0')
           << world->state->playerInfo.displayedMoney;

        ti.text = GameSymbols::Money + GameStringUtil::fromString(ss.str(), ti.font);
    }

    ti.baseColour = hudParameters.uiShadowColour;
    ti.screenPosition = glm::vec2(infoTextX + 1.f, infoTextY + 1.f);
    render.text.renderText(ti);

    ti.baseColour = hudParameters.uiMoneyColour;

    ti.screenPosition = glm::vec2(infoTextX, infoTextY);
    render.text.renderText(ti);

    infoTextY += textHeight;

    if ((world->state->hudFlash != HudFlash::FlashHealth &&
         player->getCharacter()->getCurrentState().health > hudParameters.uiLowHealth) ||
        std::fmod(world->getGameTime(), 0.5f) >=
            .25f) {  // UI: Blinking health indicator if health is low
        std::stringstream ss;
        ss << std::setw(3) << std::setfill('0')
           << static_cast<int>(
                  player->getCharacter()->getCurrentState().health);
        ti.text = GameSymbols::Heart + GameStringUtil::fromString(ss.str(), ti.font);

        ti.baseColour = hudParameters.uiShadowColour;
        ti.screenPosition = glm::vec2(infoTextX + 1.f, infoTextY + 1.f);

        render.text.renderText(ti);

        ti.baseColour = hudParameters.uiHealthColour;
        ti.screenPosition = glm::vec2(infoTextX, infoTextY);
        render.text.renderText(ti);
    }

    if (player->getCharacter()->getCurrentState().armour > 0) {
        std::stringstream ss;
        ss << std::setw(3) << std::setfill('0')
           << static_cast<int>(
                  player->getCharacter()->getCurrentState().armour);
        ti.text = GameSymbols::Armour + GameStringUtil::fromString(ss.str(), ti.font);

        ti.baseColour = hudParameters.uiShadowColour;
        ti.screenPosition =
            glm::vec2(infoTextX + 1.f - hudParameters.uiArmourOffset * designScale, infoTextY + 1.f);
        render.text.renderText(ti);

        ti.baseColour = hudParameters.uiArmourColour;
        ti.screenPosition = glm::vec2(infoTextX - hudParameters.uiArmourOffset * designScale, infoTextY);
        render.text.renderText(ti);
    }

    GameString s;
    for (size_t i = 0; i < hudParameters.uiMaxWantedLevel; ++i) {
        s += GameSymbols::Star;
    }
    ti.text = s;
    ti.baseColour = hudParameters.uiShadowColour;
    ti.screenPosition = glm::vec2(wantedX + 1.f, wantedY + 1.f);
    render.text.renderText(ti);

#if 0  // Useful for debugging
	ti.text = "ABCDEFGHIJKLMANOQRTSWXYZ\nM0123456789";
	ti.size = 30;
	ti.align = TextRenderer::TextInfo::Left;
	ti.baseColour = glm::vec3(0.f, 0.f, 0.f);
	ti.screenPosition = glm::vec2(101.f, 202.f);
    render.text.renderText(ti);
	ti.baseColour = glm::vec3(1.f, 1.f, 1.f);
	ti.screenPosition = glm::vec2(100.f, 200.f);
    render.text.renderText(ti);
#endif

    auto item = player->getCharacter()->getActiveItem();
    const auto& weapon = world->data->weaponData[item];
    std::string itemTextureName = "fist";
    if (weapon.modelID > 0) {
        auto model =
            world->data->findModelInfo<SimpleModelInfo>(weapon.modelID);
        if (model != nullptr) {
            itemTextureName = model->name;
        }
    }
    // Urgh
    if (itemTextureName == "colt45") {
        itemTextureName = "pistol";
    } else if (itemTextureName == "bomb") {
        itemTextureName = "detonator";
    }

    auto itemTexturePtr =
        render.getData().findSlotTexture("hud", itemTextureName);
    RW_CHECK(itemTexturePtr != nullptr, "Item has 0 texture");
    if (itemTexturePtr != nullptr) {
        RW_CHECK(itemTexturePtr->getName() != 0, "Item has 0 texture");
        render.drawTexture(itemTexturePtr,
                           glm::vec4(iconX, iconY, weaponSize,
                                     weaponSize));
    }

    if (weapon.fireType != WeaponData::MELEE) {
        const CharacterState& cs = player->getCharacter()->getCurrentState();
        const CharacterWeaponSlot& slotInfo = cs.weapons[cs.currentWeapon];

        // In weapon.dat clip size of 0 or 1000+ indicates no reload
        // Clip size of 1 is being visually omitted as well
        bool noClip = weapon.clipSize < 2 || weapon.clipSize > 999;

        uint32_t displayBulletsTotal = slotInfo.bulletsTotal;

        if (noClip) {
            // The clip is actually there, but it holds just one shot/charge
            displayBulletsTotal += slotInfo.bulletsClip;

            ti.text =
                GameStringUtil::fromString(std::to_string(displayBulletsTotal), ti.font);
        } else {
            // Limit the maximal displayed length for the total bullet count
            if (slotInfo.bulletsTotal > 9999) {
                displayBulletsTotal = 9999;
            }

            ti.text = GameStringUtil::fromString(
                std::to_string(displayBulletsTotal) + "-" +
                std::to_string(slotInfo.bulletsClip), ti.font);
        }

        ti.baseColour = hudParameters.uiShadowColour;
        ti.font = FONT_ARIAL;
        ti.size = hudParameters.uiAmmoSize * designScale;
        ti.align = TextRenderer::TextInfo::TextAlignment::Center;
        ti.screenPosition = glm::vec2(iconX + weaponSize / 2.f,
                                      iconY + weaponSize - hudParameters.uiAmmoHeight * designScale);
        render.text.renderText(ti);
    }
}

void HUDDrawer::drawHUD(ViewCamera& currentView, ai::PlayerController* player,
                        GameWorld* world, GameRenderer& render) {
    // The 2D projection spans the logical (window) size; the HUD parameters
    // are in GTA III design pixels (reference height kScreenVirtualHeight).
    // Scale them so HUD elements keep their visual size across resolutions.
    designScale = render.getLogicalSize().y / kScreenVirtualHeight;
    if (player && player->getCharacter()) {
        drawMap(currentView, player, world, render);
        drawPlayerInfo(player, world, render);
        drawScriptTimer(world, render);
    }
}

void HUDDrawer::drawOnScreenText(GameWorld* world, GameRenderer& renderer) {
    designScale = renderer.getLogicalSize().y / kScreenVirtualHeight;
    const auto vp = glm::vec2(renderer.getLogicalSize());

    TextRenderer::TextInfo ti;
    ti.font = FONT_ARIAL;
    ti.screenPosition = glm::vec2(10.f, 10.f) * designScale;
    ti.size = 20.f * designScale;

    auto& alltext = world->state->text.getAllText();

    for (auto& l : alltext) {
        for (auto& t : l) {
            ti.size = static_cast<float>(t.size * hudParameters.hudScale *
                                         designScale);
            ti.font = t.font;
            ti.text = t.text;
            // wrapX is authored in 640x480 design space (set by opcode 0343
            // set_text_linewidth, currently unimplemented). TextRenderer
            // compares it against a lineLength accumulated in ti.size units
            // (already scaled by designScale here), so it must be scaled the
            // same way once 0343 is implemented -- otherwise wrapping breaks.
            ti.wrapX = t.wrapX;
            ti.screenPosition =
                (t.position / glm::vec2(kScreenVirtualWidth, kScreenVirtualHeight)) * vp;
            switch (t.alignment) {
                case 0:
                    ti.align = TextRenderer::TextInfo::TextAlignment::Left;
                    break;
                case 1:
                    ti.align = TextRenderer::TextInfo::TextAlignment::Center;
                    break;
                case 2:
                    ti.align = TextRenderer::TextInfo::TextAlignment::Right;
                    break;
            }

            // Check for the background type
            if (t.colourBG.a == 0) {
                glm::vec2 shadowPosition(static_cast<int8_t>(t.colourBG.x),
                                         static_cast<int8_t>(t.colourBG.y));

                ti.baseColour = glm::vec3(0.f);
                ti.screenPosition += shadowPosition;
                ti.backgroundColour = {0, 0, 0, 0};

                renderer.text.renderText(ti, true);

                ti.screenPosition -= shadowPosition;
            } else if (t.colourBG.a > 0) {
                ti.backgroundColour = t.colourBG;
            }

            ti.baseColour = t.colourFG;
            renderer.text.renderText(ti);
        }
    }
}

void HUDDrawer::applyHUDScale(float scale) {
    hudParameters.hudScale = scale;
    hudParameters.uiTextSize *= scale;
    hudParameters.uiTextHeight *= scale;
    hudParameters.uiElementMargin *= scale;
    hudParameters.uiOuterMargin *= scale;
    hudParameters.uiInfoMargin *= scale;
    hudParameters.uiWeaponSize *= scale;
    hudParameters.uiAmmoSize *= scale;
    hudParameters.uiAmmoHeight *= scale;
    hudParameters.uiWantedLevelHeight *= scale;
    hudParameters.uiScriptTimerHeight *= scale;
    hudParameters.uiArmourOffset *= scale;
    hudParameters.uiMapSize *= scale;
}

HUDDrawer::HUDParameters HUDDrawer::getHUDParameters() {
    return hudParameters;
}
