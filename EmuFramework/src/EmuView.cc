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

#include <EmuView.hh>
#include <EmuInput.hh>
#include <VController.hh>
#include <EmuApp.hh>
#include <algorithm>

void EmuView::draw(Base::FrameTimeBase frameTime)
{
	using namespace Gfx;
	if(layer)
	{
		layer->draw(frameTime, projP);
	}
	if(EmuSystem::isActive() && inputView)
	{
		loadTransform(projP.makeTranslate());
		inputView->draw(frameTime);
	}
}

void EmuView::place()
{
	if(layer)
	{
		layer->place(viewRect(), projP, inputView);
	}
	if(inputView)
	{
		inputView->place();
	}
}

void EmuView::inputEvent(const Input::Event &e)
{
	if(inputView)
	{
		inputView->inputEvent(e);
	}
}
