#pragma once

/*  This file is part of EmuFramework.

	Imagine is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Imagine is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with EmuFramework.  If not, see <http://www.gnu.org/licenses/> */

#include <imagine/gfx/GfxSprite.hh>
#include <imagine/gfx/Texture.hh>
#include <imagine/gfx/TextureSampler.hh>
#include <imagine/util/enum.hh>

namespace EmuEx
{

using namespace IG;

WISE_ENUM_CLASS((ImageOverlayId, uint8_t),
	(SCANLINES, 1),
	(SCANLINES_2, 2),
	(LCD, 10),
	(CRT_MASK, 20),
	(CRT_MASK_2, 21),
	(CRT_GRILLE, 30),
	(CRT_GRILLE_2, 31));

class VideoImageOverlay
{
public:
	constexpr	VideoImageOverlay() = default;
	void setEffect(Gfx::Renderer &, ImageOverlayId, Gfx::ColorSpace);
	void setIntensity(float intensity);
	void place(const Gfx::Sprite &, WP videoPixels, IG::Rotation);
	void draw(Gfx::RendererCommands &cmds, float brightness);

private:
	Gfx::Texture img{};
	Gfx::Sprite spr{};
	Gfx::TextureSampler sampler{};
	float intensity = 0.75f;
	ImageOverlayId overlayId{};
	bool multiplyBlend{};
};

}
