东方同人游戏引擎使用手册
第一部分 配置
引擎配置 [Config.xml]
1.	强制同步FPS  //引擎会根据子弹速度自动设置FPS 高速子弹拥有更高的FPS 启用可减少视觉差异  （关闭）
2.	自动全屏  //程序启动时不自动全屏 （启用）
3.	后续补充
游戏配置[Game.xml]
1.	后续补充
2.	后续补充
关卡配置[Level.xml]
1.	后续补充
第二部分 内容
游戏 [Game.xml]
1.	Name 游戏名称
属性：font 用于控制字体 (可选)（可为文件或字体名）
2.	Background 程序背景
3.	Forgeground 立绘 （可选）
4.	Players 可选角色列表
5.	   Player 角色
6.	      Life 生命值
7.	      Shoot 子弹样式
8.	      AttackPower 攻击力（每 点 ）




关卡[Level.xml]
1.	HardLevel 难度 示例：Easy，Normal，Hard
2.	   Boss 该难度关卡 敌人
3.	      SpellCard 符卡

符卡[SpellName.xml]     注：储存在.\\Resources\\SpellCard
1.	SpellCardName 符卡名
2.	SpellCardTime 符卡时间
3.	SpellLife 符卡生命
4.	Functions 函数列表
5.	   Excuse 执行 （单次 同时）
6.	      Function 函数
7.	         Parameter… 参数 （多个）


第三部分 错误
类型
1.	灾难性（Fault）极其严重的错误 引擎无法继续运行
2.	错误（Error） 较严重地错误 对游戏体验有较大影响
3.	警告（Warn）较轻微错误 可能影响游戏体验
4.	信息（Info）对游戏体验无影响
灾难性
1.	所有由C++、操作系统发出的错误
2.	缺失Game.xml
3.	缺失Level.xml
错误
1.	缺失 图片、音乐 等资源
警告
1. 后续追加
终章
适用人员
1.  玩家 请阅读 第三部分
2.  开发人员 请阅读 全部部分
3.  设计人员 请阅读 第一、二、三、四部分

许可
本文 及 本游戏引擎 均使用 GPL v3许可协议 ， 开源 免费 地提供给所有人。使用者可以 使用 转载 复制本文 及 部分本文 复制程序代码 及 部分代码  但 不得用于商业 且 必须保留原许可 并明确注释、提示 修改。本文及本程序 作者 不对不法使用该文档和程序、程序源代码 负任何法律责任

