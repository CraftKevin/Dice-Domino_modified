/*
 *  _______     ________    ________    ________    __
 * |   __  \   |__    __|  |   _____|  |   _____|  |  |
 * |  |  |  |     |  |     |  |        |  |_____   |  |
 * |  |  |  |     |  |     |  |        |   _____|  |__|
 * |  |__|  |   __|  |__   |  |_____   |  |_____    __
 * |_______/   |________|  |________|  |________|  |__|
 *
 * Dice! QQ Dice Robot for TRPG
 * Copyright (C) 2018 w4123溯洄
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
		{ "strSetInvalid", "无效的默认骰!请输入1-99999之间的数字!" },
		{ "strSetTooBig", "默认骰过大!请输入1-99999之间的数字!" },
		{ "strSetCannotBeZero", "默认骰不能为零!请输入1-99999之间的数字!" },
		{ "strCharacterCannotBeZero", "人物作成次数不能为零!请输入1-10之间的数字!" },
		{ "strSetInvalid", "无效的默认骰!请输入1-99999之间的数字!" },
		{ "strSetTooBig", "默认骰过大!请输入1-99999之间的数字!" },
		{ "strSetCannotBeZero", "默认骰不能为零!请输入1-99999之间的数字!" },
		{ "strCharacterCannotBeZero", "人物作成次数不能为零!请输入1-10之间的数字!" },
		{ "strCharacterTooBig", "人物作成次数过多!请输入1-10之间的数字!" },
		{ "strCharacterInvalid", "人物作成次数无效!请输入1-10之间的数字!" },
		{ "strSCInvalid", "SanCheck会不会啊笨蛋(╯‵□′)╯︵┻━┻,格式为成功扣San/失败扣San,如1/1d6!" },
		{ "strSanInvalid", "你这个San值要闹哪样啊！请输入1-99范围内的整数!" },
		{ "strEnValInvalid", "你这个技能值要闹哪样啊！请输入1-99范围内的整数!" },
		{ "strGroupIDInvalid", "唔…这个群号本大爷查不到啊……!" },
		{ "strSendErr", "消息没法过去耶……别问我为什么，我也不知道……" },
		{ "strDisabledErr", "你让我骰我就骰，那本大爷岂不是很没面子？！（机器人已在此群中被关闭!）" },
		{ "strMEDisabledErr", "管理员已在此群中禁用.me命令!" },
		{ "strHELPDisabledErr", "管理员已在此群中禁用.help命令!" },
		{ "strNameDelErr", "没有设置名称,无法删除!" },
		{ "strValueErr", "会不会丢骰子啊笨蛋(╯‵□′)╯︵┻━┻" },
		{ "strInputErr", "命令或掷骰表达式输错了啊蠢货(╯‵□′)╯︵┻━┻!" },
		{ "strUnknownErr", "啊！好像出错了……别问我为什么，我也不知道……" },
		{ "strDiceTooBigErr", "这么多骰子！你等着，本大爷先数数……" },
		{ "strTypeTooBigErr", "你给我等着！本大爷先数完这骰子有多少面——" },
		{ "strZeroTypeErr", "这是...!!时空裂(682被骰子产生的时空裂缝卷走了)" },
		{ "strAddDiceValErr", "你这样要让我扔骰子扔到什么时候嘛！(╯‵□′)╯︵┻━┻(请输入正确的加骰参数:5-10之内的整数)" },
		{ "strZeroDiceErr", "诶?本大爷的骰子呢?" },
		{ "strRollTimeExceeded", "掷骰轮数超过了最大轮数限制!" },
		{ "strRollTimeErr", "异常的掷骰轮数" },
		{ "strWelcomeMsgClearNotice", "已清除本群的入群欢迎词" },
		{ "strWelcomeMsgClearErr", "错误:没有设置入群欢迎词，清除失败" },
		{ "strWelcomeMsgUpdateNotice", "知道啦，以后有新的D级来了本大爷就这么说——" },
		{ "strPermissionDeniedErr", "诶嘿，你不是管理员，本大爷不听你的！" },
		{ "strNameTooLongErr", "名字太长，本大爷记不住！" },
		{ "strUnknownPropErr", "这是什么属性，本大爷不知道啊！（属性不存在）" },
		{ "strEmptyWWDiceErr", "格式错误:正确格式为.w(w)XaY!其中X≥1, 5≤Y≤10" },
		{ "strPropErr", "认真的给本大爷输入你的属性！" },
		{ "strSetPropSuccess", "本大爷记住你的属性了！" },
		{ "strPropCleared", "我已经把你的属性忘光啦！" },
		{ "strRuleErr", "规则数据获取失败,具体信息:\n" },
		{ "strRulesFailedErr", "请求失败,无法连接数据库" },
		{ "strPropDeleted", "那我把它忘掉了嗷！" },
		{ "strPropNotFound", "错误:属性不存在" },
		{ "strRuleNotFound", "未找到对应的规则信息" },
		{ "strProp", "{0}的{1}属性值为{2}" },
		{ "strStErr", "你输入错误了啦，笨蛋——找个大佬问问.st命令的用法吧！" },
		{ "strRulesFormatErr", "格式错误:正确格式为.rules[规则名称:]规则条目 如.rules COC7:力量" },
		{ "strHlpMsg" , Dice_Short_Ver + "\n" +
		R"(哈？本大爷才没有灌铅！
请使用"!dismiss"命令使682退群！！
本大爷除了骰子之外，还有好多别的功能——具体指令列表请参考:https://dicer.club/?p=117
<通用命令>
.r [掷骰表达式*] [原因]			普通掷骰
.rs	[掷骰表达式*] [原因]			简化输出
.w/ww XaY						骰池
.set [1-99999之间的整数]			设置默认骰
.sc SC表达式** [San值]			自动Sancheck
.en [技能名] [技能值]			增强检定/幕间成长
.coc7/6 [个数]					COC7/6人物作成
.dnd [个数]					DND人物作成
.coc7/6d					详细版COC7/6人物作成
.ti/li					疯狂发作-临时/总结症状
.st [del/clr/show] [属性名] [属性值]		人物卡导入
.rc/ra [技能名] [技能值]		技能检定(规则书/房规)
.jrrp [on/off]				今日人品检定
.rules [规则名称:]规则条目		规则查询
.help						显示帮助
<仅限群/多人聊天>
.ri [加值] [昵称]			DnD先攻掷骰
.init [clr]					DnD先攻查看/清空
.nn [名称]					设置/删除昵称
.rh [掷骰表达式*] [原因]			暗骰,结果私聊发送
.bot [on/off] [机器人QQ号]		机器人开启或关闭
.ob [exit/list/clr/on/off]			旁观模式
.me on/off/动作				以第三方视角做出动作
.welcome 欢迎消息				群欢迎提示
<仅限私聊>
.me 群号 动作				以第三方视角做出动作
*COC7惩罚骰为P+个数,奖励骰为B+个数
 支持使用K来取较大的几个骰子
 支持使用 个数#表达式 进行多轮掷骰
**SC表达式为 成功扣San/失败扣San,如:1/1d6

682的收容室（水群）：937784321
机娘搭建群：837768536)" }
	};