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
#pragma once
#ifndef _RDCONSTANT_
#define _RDCONSTANT_
#include <string>

#if !defined WIN32
#error 请使用Win32(x86)模式进行编译
#endif
//Version
static const std::string Dice_Ver = "2.3.4(498)";
static const std::string Dice_Short_Ver = "Dice! by 溯洄_多米诺魔改 ver" + Dice_Ver;
static const std::string Dice_Full_Ver = Dice_Short_Ver;// +" [MSVC " + std::to_string(_MSC_FULL_VER) + " " + __DATE__ +
//	" " + __TIME__ + "]";
//Error Handle
#define Value_Err (-1)
#define Input_Err (-2)
#define ZeroDice_Err (-3)
#define ZeroType_Err (-4)
#define DiceTooBig_Err (-5)
#define TypeTooBig_Err (-6)
#define AddDiceVal_Err (-7)
//Dice Type
#define Normal_Dice 0
#define B_Dice 1
#define P_Dice 2
#define Fudge_Dice 3
#define WW_Dice 4
//Message Type
#define PrivateMsg 0
#define GroupMsg 1
#define DiscussMsg 2
//Source type
#define PrivateT 0
#define GroupT 1
#define DiscussT 2

static std::string format(std::string str, std::initializer_list<std::string> replace_str)
{
	auto counter = 0;
	for (const auto& element : replace_str)
	{
		auto replace = "{" + std::to_string(counter) + "}";
		auto replace_pos = str.find(replace);
		while (replace_pos != std::string::npos)
		{
			str.replace(replace_pos, replace.length(), element);
			replace_pos = str.find(replace);
		}
		counter++;
	}
	return str;
}

typedef int int_errno;

struct RP
{
	int RPVal;
	std::string Date;
};

static std::map<std::string, std::string> SkillNameReplace = {
	{"str", "力量"},
	{"dex", "敏捷"},
	{"pow", "意志"},
	{"siz", "体型"},
	{"app", "外貌"},
	{"luck", "幸运"},
	{"luk", "幸运"},
	{"con", "体质"},
	{"int", "智力/灵感"},
	{"智力", "智力/灵感"},
	{"灵感", "智力/灵感"},
	{"idea", "智力/灵感"},
	{"edu", "教育"},
	{"mov", "移动力"},
	{"san", "理智"},
	{"hp", "体力"},
	{"mp", "魔法"},
	{"侦察", "侦查"},
	{"计算机", "计算机使用"},
	{"电脑", "计算机使用"},
	{"电脑使用", "计算机使用"},
	{"信誉", "信用评级"},
	{"信誉度", "信用评级"},
	{"信用度", "信用评级"},
	{"信用", "信用评级"},
	{"驾驶", "汽车驾驶"},
	{"驾驶汽车", "汽车驾驶"},
	{"驾驶(汽车)", "汽车驾驶"},
	{"驾驶:汽车", "汽车驾驶"},
	{"快速交谈", "话术"},
	{"步枪", "步枪/霰弹枪"},
	{"霰弹枪", "步枪/霰弹枪"},
	{"散弹枪", "步枪/霰弹枪"},
	{"步霰", "步枪/霰弹枪"},
	{"步/霰", "步枪/霰弹枪"},
	{"步散", "步枪/霰弹枪"},
	{"步/散", "步枪/霰弹枪"},
	{"图书馆", "图书馆使用"},
	{"机修", "机械维修"},
	{"电器维修", "电气维修"},
	{"cm", "克苏鲁神话"},
	{"克苏鲁", "克苏鲁神话"},
	{"唱歌", "歌唱"},
	{"做画", "作画"},
	{"耕做", "耕作"},
	{"机枪", "机关枪"},
	{"导航", "领航"},
	{"船", "船驾驶"},
	{"驾驶船", "船驾驶"},
	{"驾驶(船)", "船驾驶"},
	{"驾驶:船", "船驾驶"},
	{"飞行器", "飞行器驾驶"},
	{"驾驶飞行器", "飞行器驾驶"},
	{"驾驶:飞行器", "飞行器驾驶"},
	{"驾驶(飞行器)", "飞行器驾驶"}
};

static std::map<std::string, int> SkillDefaultVal = {
	{"会计", 5},
	{"人类学", 1},
	{"估价", 5},
	{"考古学", 1},
	{"作画", 5},
	{"摄影", 5},
	{"表演", 5},
	{"伪造", 5},
	{"文学", 5},
	{"书法", 5},
	{"乐理", 5},
	{"厨艺", 5},
	{"裁缝", 5},
	{"理发", 5},
	{"建筑", 5},
	{"舞蹈", 5},
	{"酿酒", 5},
	{"捕鱼", 5},
	{"歌唱", 5},
	{"制陶", 5},
	{"雕塑", 5},
	{"杂技", 5},
	{"风水", 5},
	{"技术制图", 5},
	{"耕作", 5},
	{"打字", 5},
	{"速记", 5},
	{"魅惑", 15},
	{"攀爬", 20},
	{"计算机使用", 5},
	{"克苏鲁神话", 0},
	{"乔装", 5},
	{"汽车驾驶", 20},
	{"电气维修", 10},
	{"电子学", 1},
	{"话术", 5},
	{"鞭子", 5},
	{"电锯", 10},
	{"斧", 15},
	{"剑", 20},
	{"绞具", 25},
	{"链枷", 25},
	{"矛", 25},
	{"手枪", 20},
	{"步枪/霰弹枪", 25},
	{"冲锋枪", 15},
	{"弓术", 15},
	{"火焰喷射器", 10},
	{"机关枪", 10},
	{"重武器", 10},
	{"急救", 30},
	{"历史", 5},
	{"恐吓", 15},
	{"跳跃", 20},
	{"法律", 5},
	{"图书馆使用", 20},
	{"聆听", 20},
	{"锁匠", 1},
	{"机械维修", 10},
	{"医学", 1},
	{"自然学", 10},
	{"领航", 10},
	{"神秘学", 5},
	{"操作重型机械", 1},
	{"说服", 10},
	{"飞行器驾驶", 1},
	{"船驾驶", 1},
	{"精神分析", 1},
	{"心理学", 10},
	{"骑乘", 5},
	{"地质学", 1},
	{"化学", 1},
	{"生物学", 1},
	{"数学", 1},
	{"天文学", 1},
	{"物理学", 1},
	{"药学", 1},
	{"植物学", 1},
	{"动物学", 1},
	{"密码学", 1},
	{"工程学", 1},
	{"气象学", 1},
	{"司法科学", 1},
	{"妙手", 10},
	{"侦查", 25},
	{"潜行", 20},
	{"游泳", 20},
	{"投掷", 20},
	{"追踪", 10},
	{"驯兽", 5},
	{"潜水", 1},
	{"爆破", 1},
	{"读唇", 1},
	{"催眠", 1},
	{"炮术", 1},
	{"斗殴", 25}
};

static std::string TempInsanity[11]{
	"",
	"失忆：在{0}轮之内，调查员会发现自己只记得最后身处的安全地点，却没有任何来到这里的记忆。",
	"假性残疾：调查员陷入了心理性的失明，失聪以及躯体缺失感中，持续{0}轮。",
	"暴力倾向：调查员陷入了六亲不认的暴力行为中，对周围的敌人与友方进行着无差别的攻击，持续{0}轮。",
	"偏执：调查员陷入了严重的偏执妄想之中。有人在暗中窥视着他们，同伴中有人背叛了他们，没有人可以信任，万事皆虚。持续{0}轮。",
	"人际依赖：调查员因为一些原因而将他人误认为了他重要的人并且努力的会与那个人保持那种关系，持续{0}轮。",
	"昏厥：调查员当场昏倒，昏迷状态持续{0}轮。",
	"逃避行为：调查员会用任何的手段试图逃离现在所处的位置，状态持续{0}轮。",
	"竭嘶底里：调查员表现出大笑，哭泣，嘶吼，害怕等的极端情绪表现，持续{0}轮。",
	"恐惧：调查员陷入对某一事物的恐惧之中，就算这一恐惧的事物是并不存在的，持续{0}轮。\n{1}\n具体恐惧症: {2}(守秘人也可以自行从恐惧症状表中选择其他症状)",
	"狂躁：调查员由于某种诱因进入狂躁状态，症状持续{0}轮。\n{1}\n具体狂躁症: {2}(守秘人也可以自行从狂躁症状表中选择其他症状)"
};

static std::string LongInsanity[11]{
	"",
	"失忆：在{0}小时后，调查员回过神来，发现自己身处一个陌生的地方，并忘记了自己是谁。记忆会随时间恢复。",
	"被窃：调查员在{0}小时后恢复清醒，发觉自己被盗，身体毫发无损。",
	"遍体鳞伤：调查员在{0}小时后恢复清醒，发现自己身上满是拳痕和瘀伤。生命值减少到疯狂前的一半，但这不会造成重伤。调查员没有被窃。这种伤害如何持续到现在由守秘人决定。",
	"暴力倾向：调查员陷入强烈的暴力与破坏欲之中，持续{0}小时。",
	"极端信念：在{0}小时之内，调查员会采取极端和疯狂的表现手段展示他们的思想信念之一",
	"重要之人：在{0}小时中，调查员将不顾一切地接近重要的那个人，并为他们之间的关系做出行动。",
	"被收容：{0}小时后，调查员在精神病院病房或警察局牢房中回过神来",
	"逃避行为：{0}小时后，调查员恢复清醒时发现自己在很远的地方",
	"恐惧：调查员患上一个新的恐惧症。调查员会在{0}小时后恢复正常，并开始为避开恐惧源而采取任何措施。\n{1}\n具体恐惧症: {2}(守秘人也可以自行从恐惧症状表中选择其他症状)",
	"狂躁：调查员患上一个新的狂躁症，在{0}小时后恢复理智。在这次疯狂发作中，调查员将完全沉浸于其新的狂躁症状。这是否会被其他人理解（apparent to other people）则取决于守秘人和此调查员。\n{1}\n具体狂躁症: {2}(守秘人也可以自行从狂躁症状表中选择其他症状)"
};

static std::string strFear[101] = {
	"",
	"洗澡恐惧症（Ablutophobia）：对于洗涤或洗澡的恐惧。",
	"恐高症（Acrophobia）：对于身处高处的恐惧。",
	"飞行恐惧症（Aerophobia）：对飞行的恐惧。",
	"广场恐惧症（Agoraphobia）：对于开放的（拥挤）公共场所的恐惧。",
	"恐鸡症（Alektorophobia）：对鸡的恐惧。",
	"大蒜恐惧症（Alliumphobia）：对大蒜的恐惧。",
	"乘车恐惧症（Amaxophobia）：对于乘坐地面载具的恐惧。",
	"恐风症（Ancraophobia）：对风的恐惧。",
	"男性恐惧症（Androphobia）：对于成年男性的恐惧。",
	"恐英症（Anglophobia）：对英格兰或英格兰文化的恐惧。",
	"恐花症（Anthophobia）：对花的恐惧。",
	"截肢者恐惧症（Apotemnophobia）：对截肢者的恐惧。",
	"蜘蛛恐惧症（Arachnophobia）：对蜘蛛的恐惧。",
	"闪电恐惧症（Astraphobia）：对闪电的恐惧。",
	"废墟恐惧症（Atephobia）：对遗迹或残址的恐惧。",
	"长笛恐惧症（Aulophobia）：对长笛的恐惧。",
	"细菌恐惧症（Bacteriophobia）：对细菌的恐惧。",
	"导弹/子弹恐惧症（Ballistophobia）：对导弹或子弹的恐惧。",
	"跌落恐惧症（Basophobia）：对于跌倒或摔落的恐惧。",
	"书籍恐惧症（Bibliophobia）：对书籍的恐惧。",
	"植物恐惧症（Botanophobia）：对植物的恐惧。",
	"美女恐惧症（Caligynephobia）：对美貌女性的恐惧。",
	"寒冷恐惧症（Cheimaphobia）：对寒冷的恐惧。",
	"恐钟表症（Chronomentrophobia）：对于钟表的恐惧。",
	"幽闭恐惧症（Claustrophobia）：对于处在封闭的空间中的恐惧。",
	"小丑恐惧症（Coulrophobia）：对小丑的恐惧。",
	"恐犬症（Cynophobia）：对狗的恐惧。",
	"恶魔恐惧症（Demonophobia）：对邪灵或恶魔的恐惧。",
	"人群恐惧症（Demophobia）：对人群的恐惧。",
	"牙科恐惧症（Dentophobia）：对牙医的恐惧。",
	"丢弃恐惧症（Disposophobia）：对于丢弃物件的恐惧（贮藏癖）。",
	"皮毛恐惧症（Doraphobia）：对动物皮毛的恐惧。",
	"过马路恐惧症（Dromophobia）：对于过马路的恐惧。",
	"教堂恐惧症（Ecclesiophobia）：对教堂的恐惧。",
	"镜子恐惧症（Eisoptrophobia）：对镜子的恐惧。",
	"针尖恐惧症（Enetophobia）：对针或大头针的恐惧。",
	"昆虫恐惧症（Entomophobia）：对昆虫的恐惧。",
	"恐猫症（Felinophobia）：对猫的恐惧。",
	"过桥恐惧症（Gephyrophobia）：对于过桥的恐惧。",
	"恐老症（Gerontophobia）：对于老年人或变老的恐惧。",
	"恐女症（Gynophobia）：对女性的恐惧。",
	"恐血症（Haemaphobia）：对血的恐惧。",
	"宗教罪行恐惧症（Hamartophobia）：对宗教罪行的恐惧。",
	"触摸恐惧症（Haphophobia）：对于被触摸的恐惧。",
	"爬虫恐惧症（Herpetophobia）：对爬行动物的恐惧。",
	"迷雾恐惧症（Homichlophobia）：对雾的恐惧。",
	"火器恐惧症（Hoplophobia）：对火器的恐惧。",
	"恐水症（Hydrophobia）：对水的恐惧。",
	"催眠恐惧症（Hypnophobia）：对于睡眠或被催眠的恐惧。",
	"白袍恐惧症（Iatrophobia）：对医生的恐惧。",
	"鱼类恐惧症（Ichthyophobia）：对鱼的恐惧。",
	"蟑螂恐惧症（Katsaridaphobia）：对蟑螂的恐惧。",
	"雷鸣恐惧症（Keraunophobia）：对雷声的恐惧。",
	"蔬菜恐惧症（Lachanophobia）：对蔬菜的恐惧。",
	"噪音恐惧症（Ligyrophobia）：对刺耳噪音的恐惧。",
	"恐湖症（Limnophobia）：对湖泊的恐惧。",
	"机械恐惧症（Mechanophobia）：对机器或机械的恐惧。",
	"巨物恐惧症（Megalophobia）：对于庞大物件的恐惧。",
	"捆绑恐惧症（Merinthophobia）：对于被捆绑或紧缚的恐惧。",
	"流星恐惧症（Meteorophobia）：对流星或陨石的恐惧。",
	"孤独恐惧症（Monophobia）：对于一人独处的恐惧。",
	"不洁恐惧症（Mysophobia）：对污垢或污染的恐惧。",
	"黏液恐惧症（Myxophobia）：对黏液（史莱姆）的恐惧。",
	"尸体恐惧症（Necrophobia）：对尸体的恐惧。",
	"数字8恐惧症（Octophobia）：对数字8的恐惧。",
	"恐牙症（Odontophobia）：对牙齿的恐惧。",
	"恐梦症（Oneirophobia）：对梦境的恐惧。",
	"称呼恐惧症（Onomatophobia）：对于特定词语的恐惧。",
	"恐蛇症（Ophidiophobia）：对蛇的恐惧。",
	"恐鸟症（Ornithophobia）：对鸟的恐惧。",
	"寄生虫恐惧症（Parasitophobia）：对寄生虫的恐惧。",
	"人偶恐惧症（Pediophobia）：对人偶的恐惧。",
	"吞咽恐惧症（Phagophobia）：对于吞咽或被吞咽的恐惧。",
	"药物恐惧症（Pharmacophobia）：对药物的恐惧。",
	"幽灵恐惧症（Phasmophobia）：对鬼魂的恐惧。",
	"日光恐惧症（Phenogophobia）：对日光的恐惧。",
	"胡须恐惧症（Pogonophobia）：对胡须的恐惧。",
	"河流恐惧症（Potamophobia）：对河流的恐惧。",
	"酒精恐惧症（Potophobia）：对酒或酒精的恐惧。",
	"恐火症（Pyrophobia）：对火的恐惧。",
	"魔法恐惧症（Rhabdophobia）：对魔法的恐惧。",
	"黑暗恐惧症（Scotophobia）：对黑暗或夜晚的恐惧。",
	"恐月症（Selenophobia）：对月亮的恐惧。",
	"火车恐惧症（Siderodromophobia）：对于乘坐火车出行的恐惧。",
	"恐星症（Siderophobia）：对星星的恐惧。",
	"狭室恐惧症（Stenophobia）：对狭小物件或地点的恐惧。",
	"对称恐惧症（Symmetrophobia）：对对称的恐惧。",
	"活埋恐惧症（Taphephobia）：对于被活埋或墓地的恐惧。",
	"公牛恐惧症（Taurophobia）：对公牛的恐惧。",
	"电话恐惧症（Telephonophobia）：对电话的恐惧。",
	"怪物恐惧症①（Teratophobia）：对怪物的恐惧。",
	"深海恐惧症（Thalassophobia）：对海洋的恐惧。",
	"手术恐惧症（Tomophobia）：对外科手术的恐惧。",
	"十三恐惧症（Triskadekaphobia）：对数字13的恐惧症。",
	"衣物恐惧症（Vestiphobia）：对衣物的恐惧。",
	"女巫恐惧症（Wiccaphobia）：对女巫与巫术的恐惧。",
	"黄色恐惧症（Xanthophobia）：对黄色或“黄”字的恐惧。",
	"外语恐惧症（Xenoglossophobia）：对外语的恐惧。",
	"异域恐惧症（Xenophobia）：对陌生人或外国人的恐惧。",
	"动物恐惧症（Zoophobia）：对动物的恐惧。"
};
static std::string strPanic[101] = {
	"",
	"沐浴癖（Ablutomania）：执着于清洗自己。",
	"犹豫癖（Aboulomania）：病态地犹豫不定。",
	"喜暗狂（Achluomania）：对黑暗的过度热爱。",
	"喜高狂（Acromaniaheights）：狂热迷恋高处。",
	"亲切癖（Agathomania）：病态地对他人友好。",
	"喜旷症（Agromania）：强烈地倾向于待在开阔空间中。",
	"喜尖狂（Aichmomania）：痴迷于尖锐或锋利的物体。",
	"恋猫狂（Ailuromania）：近乎病态地对猫友善。",
	"疼痛癖（Algomania）：痴迷于疼痛。",
	"喜蒜狂（Alliomania）：痴迷于大蒜。",
	"乘车癖（Amaxomania）：痴迷于乘坐车辆。",
	"欣快癖（Amenomania）：不正常地感到喜悦。",
	"喜花狂（Anthomania）：痴迷于花朵。",
	"计算癖（Arithmomania）：狂热地痴迷于数字。",
	"消费癖（Asoticamania）：鲁莽冲动地消费。",
	"隐居癖（Automania）：过度地热爱独自隐居。",
	"芭蕾癖（Balletmania）：痴迷于芭蕾舞。",
	"窃书癖（Biliokleptomania）：无法克制偷窃书籍的冲动。",
	"恋书狂（Bibliomania）：痴迷于书籍和/或阅读",
	"磨牙癖（Bruxomania）：无法克制磨牙的冲动。",
	"灵臆症（Cacodemomania）：病态地坚信自己已被一个邪恶的灵体占据。",
	"美貌狂（Callomania）：痴迷于自身的美貌。",
	"地图狂（Cartacoethes）：在何时何处都无法控制查阅地图的冲动。",
	"跳跃狂（Catapedamania）：痴迷于从高处跳下。",
	"喜冷症（Cheimatomania）：对寒冷或寒冷的物体的反常喜爱。",
	"舞蹈狂（Choreomania）：无法控制地起舞或发颤。",
	"恋床癖（Clinomania）：过度地热爱待在床上。",
	"恋墓狂（Coimetormania）：痴迷于墓地。",
	"色彩狂（Coloromania）：痴迷于某种颜色。",
	"小丑狂（Coulromania）：痴迷于小丑。",
	"恐惧狂（Countermania）：执着于经历恐怖的场面。",
	"杀戮癖（Dacnomania）：痴迷于杀戮。",
	"魔臆症（Demonomania）：病态地坚信自己已被恶魔附身。",
	"抓挠癖（Dermatillomania）：执着于抓挠自己的皮肤。",
	"正义狂（Dikemania）：痴迷于目睹正义被伸张。",
	"嗜酒狂（Dipsomania）：反常地渴求酒精。",
	"毛皮狂（Doramania）：痴迷于拥有毛皮。",
	"赠物癖（Doromania）：痴迷于赠送礼物。",
	"漂泊症（Drapetomania）：执着于逃离。",
	"漫游癖（Ecdemiomania）：执着于四处漫游。",
	"自恋狂（Egomania）：近乎病态地以自我为中心或自我崇拜。",
	"职业狂（Empleomania）：对于工作的无尽病态渴求。",
	"臆罪症（Enosimania）：病态地坚信自己带有罪孽。",
	"学识狂（Epistemomania）：痴迷于获取学识。",
	"静止癖（Eremiomania）：执着于保持安静。",
	"乙醚上瘾（Etheromania）：渴求乙醚。",
	"求婚狂（Gamomania）：痴迷于进行奇特的求婚。",
	"狂笑癖（Geliomania）：无法自制地，强迫性的大笑。",
	"巫术狂（Goetomania）：痴迷于女巫与巫术。",
	"写作癖（Graphomania）：痴迷于将每一件事写下来。",
	"裸体狂（Gymnomania）：执着于裸露身体。",
	"妄想狂（Habromania）：近乎病态地充满愉快的妄想（而不顾现实状况如何）。",
	"蠕虫狂（Helminthomania）：过度地喜爱蠕虫。",
	"枪械狂（Hoplomania）：痴迷于火器。",
	"饮水狂（Hydromania）：反常地渴求水分。",
	"喜鱼癖（Ichthyomania）：痴迷于鱼类。",
	"图标狂（Iconomania）：痴迷于图标与肖像",
	"偶像狂（Idolomania）：痴迷于甚至愿献身于某个偶像。",
	"信息狂（Infomania）：痴迷于积累各种信息与资讯。",
	"射击狂（Klazomania）：反常地执着于射击。",
	"偷窃癖（Kleptomania）：反常地执着于偷窃。",
	"噪音癖（Ligyromania）：无法自制地执着于制造响亮或刺耳的噪音。",
	"喜线癖（Linonomania）：痴迷于线绳。",
	"彩票狂（Lotterymania）：极端地执着于购买彩票。",
	"抑郁症（Lypemania）：近乎病态的重度抑郁倾向。",
	"巨石狂（Megalithomania）：当站在石环中或立起的巨石旁时，就会近乎病态地写出各种奇怪的创意。",
	"旋律狂（Melomania）：痴迷于音乐或一段特定的旋律。",
	"作诗癖（Metromania）：无法抑制地想要不停作诗。",
	"憎恨癖（Misomania）：憎恨一切事物，痴迷于憎恨某个事物或团体。",
	"偏执狂（Monomania）：近乎病态地痴迷与专注某个特定的想法或创意。",
	"夸大癖（Mythomania）：以一种近乎病态的程度说谎或夸大事物。",
	"臆想症（Nosomania）：妄想自己正在被某种臆想出的疾病折磨。",
	"记录癖（Notomania）：执着于记录一切事物（例如摄影）",
	"恋名狂（Onomamania）：痴迷于名字（人物的、地点的、事物的）",
	"称名癖（Onomatomania）：无法抑制地不断重复某个词语的冲动。",
	"剔指癖（Onychotillomania）：执着于剔指甲。",
	"恋食癖（Opsomania）：对某种食物的病态热爱。",
	"抱怨癖（Paramania）：一种在抱怨时产生的近乎病态的愉悦感。",
	"面具狂（Personamania）：执着于佩戴面具。",
	"幽灵狂（Phasmomania）：痴迷于幽灵。",
	"谋杀癖（Phonomania）：病态的谋杀倾向。",
	"渴光癖（Photomania）：对光的病态渴求。",
	"背德癖（Planomania）：病态地渴求违背社会道德",
	"求财癖（Plutomania）：对财富的强迫性的渴望。",
	"欺骗狂（Pseudomania）：无法抑制的执着于撒谎。",
	"纵火狂（Pyromania）：执着于纵火。",
	"提问狂（Question-asking Mania）：执着于提问。",
	"挖鼻癖（Rhinotillexomania）：执着于挖鼻子。",
	"涂鸦癖（Scribbleomania）：沉迷于涂鸦。",
	"列车狂（Siderodromomania）：认为火车或类似的依靠轨道交通的旅行方式充满魅力。",
	"臆智症（Sophomania）：臆想自己拥有难以置信的智慧。",
	"科技狂（Technomania）：痴迷于新的科技。",
	"臆咒狂（Thanatomania）：坚信自己已被某种死亡魔法所诅咒。",
	"臆神狂（Theomania）：坚信自己是一位神灵。",
	"抓挠癖（Titillomaniac）：抓挠自己的强迫倾向。",
	"手术狂（Tomomania）：对进行手术的不正常爱好。",
	"拔毛癖（Trichotillomania）：执着于拔下自己的头发。",
	"臆盲症（Typhlomania）：病理性的失明。",
	"嗜外狂（Xenomania）：痴迷于异国的事物。",
	"喜兽癖（Zoomania）：对待动物的态度近乎疯狂地友好。"
};
#endif /*_RDCONSTANT_*/
