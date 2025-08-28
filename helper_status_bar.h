/**
 * FusionNote - Text Editor
 * Copyright (c) 2024 Alexander (GitHub: Syneation)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 * COMMERCIAL USE EXCEPTION:
 * Notwithstanding the terms of the GNU GPL v2, commercial use of this
 * software is permitted ONLY with explicit written permission from the author.
 *
 * Commercial use includes, but is not limited to:
 * - Selling the Software or derivative works
 * - Incorporating into paid products or services
 * - Distribution as part of commercial packages
 * - Any monetization related to the Software
 *
 * For commercial licensing inquiries, contact:
 * GitHub: https://github.com/Syneation
 *
 * DISCLAIMER:
 * THE SOFTWARE IS PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS
 * TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU.
 */

#pragma once

#ifndef HELPER_STATUS_BAR_H
#define HELPER_STATUS_BAR_H

#include "fusionnote.h"

class helper_status
{
public:
    static void set_path(NotepadPlus* notepad, QString& path_file, QString new_path);
    static void set_notifications(NotepadPlus* notepad, QString& notifications , QString text_notifications);
    static void set_len_lines(NotepadPlus* notepad, int len, int lines);
    static void set_ln_col_pos(NotepadPlus* notepad, int ln, int col, int pos);
    static void set_encoding(NotepadPlus* notepad, QString encoding);
};

#endif // HELPER_STATUS_BAR_H
