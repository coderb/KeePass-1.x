/*
  KeePass Password Safe - The Open-Source Password Manager
  Copyright (C) 2003-2010 Dominik Reichl <dominik.reichl@t-online.de>

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "StdAfx.h"
#include "CharSetBasedGenerator.h"
#include "../Util/StrUtil.h"

PWG_ERROR CsbgGenerate(std::vector<WCHAR>& vOutBuffer,
	const PW_GEN_SETTINGS_EX* pSettings, CNewRandom* pRandomSource)
{
	ASSERT(pSettings != NULL);
	if(pSettings == NULL) return PWGE_NULL_PTR;
	ASSERT(pRandomSource != NULL);
	if(pRandomSource == NULL) return PWGE_NULL_PTR;

	vOutBuffer.resize(pSettings->dwLength + 2);
	vOutBuffer[pSettings->dwLength] = 0;
	vOutBuffer[pSettings->dwLength + 1] = 0;

	PwCharSet pwCharSet(pSettings->strCharSet.c_str());

	PwgPrepareCharSet(&pwCharSet, pSettings);

	for(DWORD i = 0; i < pSettings->dwLength; ++i)
	{
		WCHAR ch = PwgGenerateCharacter(pSettings, pRandomSource, &pwCharSet);

		if(ch == 0) // Failed to generate character
		{
			EraseWCharVector(vOutBuffer);
			return PWGE_TOO_FEW_CHARACTERS;
		}

		vOutBuffer[i] = ch;
	}

	return PWGE_SUCCESS;
}