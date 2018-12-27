/*
 *  _______     ________    ________    ________    __
 * |   __  \   |__    __|  |   _____|  |   _____|  |  |
 * |  |  |  |     |  |     |  |        |  |_____   |  |
 * |  |  |  |     |  |     |  |        |   _____|  |__|
 * |  |__|  |   __|  |__   |  |_____   |  |_____    __
 * |_______/   |________|  |________|  |________|  |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018 w4123���
 *
 * This program is free software: you can redistribute it and/or modify it under the terms
 * of the GNU Affero General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License along with this
 * program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "CQLogger.h"
#include "GlobalVar.h"
#include <map>
#include "RDConstant.h"

bool Enabled = false;

bool msgSendThreadRunning = false;

CQ::logger DiceLogger("Dice!");

std::map<std::string, std::string> GlobalMsg
	{
		{ "strSetInvalid", "��Ч��Ĭ����!������1-99999֮�������!" },
		{ "strSetTooBig", "Ĭ��������!������1-99999֮�������!" },
		{ "strSetCannotBeZero", "Ĭ��������Ϊ��!������1-99999֮�������!" },
		{ "strCharacterCannotBeZero", "�������ɴ�������Ϊ��!������1-10֮�������!" },
		{ "strSetInvalid", "��Ч��Ĭ����!������1-99999֮�������!" },
		{ "strSetTooBig", "Ĭ��������!������1-99999֮�������!" },
		{ "strSetCannotBeZero", "Ĭ��������Ϊ��!������1-99999֮�������!" },
		{ "strCharacterCannotBeZero", "�������ɴ�������Ϊ��!������1-10֮�������!" },
		{ "strCharacterTooBig", "�������ɴ�������!������1-10֮�������!" },
		{ "strCharacterInvalid", "�������ɴ�����Ч!������1-10֮�������!" },
		{ "strSCInvalid", "SanCheck�᲻�ᰡ����(�s�F����)�s��ߩ���,��ʽΪ�ɹ���San/ʧ�ܿ�San,��1/1d6!" },
		{ "strSanInvalid", "�����SanֵҪ����������������1-99��Χ�ڵ�����!" },
		{ "strEnValInvalid", "���������ֵҪ����������������1-99��Χ�ڵ�����!" },
		{ "strGroupIDInvalid", "�����Ⱥ�ű���ү�鲻��������!" },
		{ "strSendErr", "��Ϣû����ȥҮ����������Ϊʲô����Ҳ��֪������" },
		{ "strDisabledErr", "���������Ҿ������Ǳ���ү���Ǻ�û���ӣ��������������ڴ�Ⱥ�б��ر�!��" },
		{ "strMEDisabledErr", "����Ա���ڴ�Ⱥ�н���.me����!" },
		{ "strHELPDisabledErr", "����Ա���ڴ�Ⱥ�н���.help����!" },
		{ "strNameDelErr", "û����������,�޷�ɾ��!" },
		{ "strValueErr", "�᲻�ᶪ���Ӱ�����(�s�F����)�s��ߩ���" },
		{ "strInputErr", "������������ʽ����˰�����(�s�F����)�s��ߩ���!" },
		{ "strUnknownErr", "������������ˡ���������Ϊʲô����Ҳ��֪������" },
		{ "strDiceTooBigErr", "��ô�����ӣ�����ţ�����ү����������" },
		{ "strTypeTooBigErr", "����ҵ��ţ�����ү�������������ж����桪��" },
		{ "strZeroTypeErr", "����...!!ʱ����(682�����Ӳ�����ʱ���ѷ������)" },
		{ "strAddDiceValErr", "������Ҫ�����������ӵ�ʲôʱ���(�s�F����)�s��ߩ���(��������ȷ�ļ�������:5-10֮�ڵ�����)" },
		{ "strZeroDiceErr", "��?����ү��������?" },
		{ "strRollTimeExceeded", "�������������������������!" },
		{ "strRollTimeErr", "�쳣����������" },
		{ "strWelcomeMsgClearNotice", "�������Ⱥ����Ⱥ��ӭ��" },
		{ "strWelcomeMsgClearErr", "����:û��������Ⱥ��ӭ�ʣ����ʧ��" },
		{ "strWelcomeMsgUpdateNotice", "֪�������Ժ����µ�D�����˱���ү����ô˵����" },
		{ "strPermissionDeniedErr", "���٣��㲻�ǹ���Ա������ү������ģ�" },
		{ "strNameTooLongErr", "����̫��������ү�ǲ�ס��" },
		{ "strUnknownPropErr", "����ʲô���ԣ�����ү��֪�����������Բ����ڣ�" },
		{ "strEmptyWWDiceErr", "��ʽ����:��ȷ��ʽΪ.w(w)XaY!����X��1, 5��Y��10" },
		{ "strPropErr", "����ĸ�����ү����������ԣ�" },
		{ "strSetPropSuccess", "����ү��ס��������ˣ�" },
		{ "strPropCleared", "���Ѿ������������������" },
		{ "strRuleErr", "�������ݻ�ȡʧ��,������Ϣ:\n" },
		{ "strRulesFailedErr", "����ʧ��,�޷��������ݿ�" },
		{ "strPropDeleted", "���Ұ���������໣�" },
		{ "strPropNotFound", "����:���Բ�����" },
		{ "strRuleNotFound", "δ�ҵ���Ӧ�Ĺ�����Ϣ" },
		{ "strProp", "{0}��{1}����ֵΪ{2}" },
		{ "strStErr", "������������������������Ҹ���������.st������÷��ɣ�" },
		{ "strRulesFormatErr", "��ʽ����:��ȷ��ʽΪ.rules[��������:]������Ŀ ��.rules COC7:����" },
		{ "strHlpMsg" , Dice_Short_Ver + "\n" +
		R"(��������ү��û�й�Ǧ��
��ʹ��"!dismiss"����ʹ682��Ⱥ����
����ү��������֮�⣬���кö��Ĺ��ܡ�������ָ���б���ο�:https://dicer.club/?p=117
<ͨ������>
.r [�������ʽ*] [ԭ��]			��ͨ����
.rs	[�������ʽ*] [ԭ��]			�����
.w/ww XaY						����
.set [1-99999֮�������]			����Ĭ����
.sc SC���ʽ** [Sanֵ]			�Զ�Sancheck
.en [������] [����ֵ]			��ǿ�춨/Ļ��ɳ�
.coc7/6 [����]					COC7/6��������
.dnd [����]					DND��������
.coc7/6d					��ϸ��COC7/6��������
.ti/li					�����-��ʱ/�ܽ�֢״
.st [del/clr/show] [������] [����ֵ]		���￨����
.rc/ra [������] [����ֵ]		���ܼ춨(������/����)
.jrrp [on/off]				������Ʒ�춨
.rules [��������:]������Ŀ		�����ѯ
.help						��ʾ����
<����Ⱥ/��������>
.ri [��ֵ] [�ǳ�]			DnD�ȹ�����
.init [clr]					DnD�ȹ��鿴/���
.nn [����]					����/ɾ���ǳ�
.rh [�������ʽ*] [ԭ��]			����,���˽�ķ���
.bot [on/off] [������QQ��]		�����˿�����ر�
.ob [exit/list/clr/on/off]			�Թ�ģʽ
.me on/off/����				�Ե������ӽ���������
.welcome ��ӭ��Ϣ				Ⱥ��ӭ��ʾ
<����˽��>
.me Ⱥ�� ����				�Ե������ӽ���������
*COC7�ͷ���ΪP+����,������ΪB+����
 ֧��ʹ��K��ȡ�ϴ�ļ�������
 ֧��ʹ�� ����#���ʽ ���ж�������
**SC���ʽΪ �ɹ���San/ʧ�ܿ�San,��:1/1d6

682�������ң�ˮȺ����937784321
����Ⱥ��837768536)" }
	};