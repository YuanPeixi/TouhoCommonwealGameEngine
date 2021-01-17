# TouhoCommonwealGameEngine
A Tiny Commonweal Game Engine bases on MFC(Microsoft Foundation Classes)
Oriental game engine manual
Part I configuration
Engine configuration[ Config.xml ]
1. Force FPS synchronization / / the engine will automatically set FPS according to bullet speed. High speed bullets have higher FPS. Enabling can reduce visual difference (off)
2. Auto full screen / / not auto full screen when the program starts (enabled)
3. Follow up supplement
Game configuration[ Game.xml ]
1. Follow up supplement
2. Follow up supplement
Level configuration[ Level.xml ]
1. Follow up supplement
The second part is content
Games[ Game.xml ]
1. Name game name
Property: font is used to control font (optional) (can be file or font name)
2. Background program background
3. Forgeground vertical drawing (optional)
4. Players optional role list
5. Player role
6. Life health
7. Shot bullet style
8. Attack power (per point)
Level[ Level.xml ]
1. Hardlevel: easy, normal, hard
2. Boss, this is the difficulty level for the enemy
3. Spellcard
Rune card[ SpellName.xml ]Note: stored in. \ \ resources \ \ spellcard
1. Spellcardname
2. Spellcardtime
3. Spell life
4. Functions list
5. Exception execution (single and simultaneous)
6. Function
7.	         Parameter…  Parameters (multiple)
Part three mistakes
type
1. Catastrophic (fault) extremely serious error, the engine can not continue to run
2. The error is more serious. The error has a great impact on the game experience
3. Warn that minor errors may affect the game experience
4. Info has no effect on the game experience
disastrous
1. All errors issued by C + +, operating system
2. Missing Game.xml
3. Missing Level.xml
error
1. Lack of pictures, music and other resources
warning
1. Subsequent addition
Final chapter
Applicable personnel
1. Please read the third part
2. Developers, please read all parts
3. Please read the first, second, third and fourth parts
permit
This article and the game engine use GPL V3 license agreement, open source free to all. Users can use reprint to copy this article and part of this article to copy the program code and part of the code, but it can not be used for business, and the original license must be retained, with clear comments and prompt for modification. The author of this article and this program does not bear any legal responsibility for the illegal use of this document, program and program source code
