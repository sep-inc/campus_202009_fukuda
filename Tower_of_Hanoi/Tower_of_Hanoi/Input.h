#ifndef INPUT_H_
#define INPUT_H_

/**
* @file Input.h
* @brief InputƒNƒ‰ƒX‚Ìƒwƒbƒ_
*/


/**
* @class Input
* @brief “ü—Íˆ—‚ğ‚Ü‚Æ‚ß‚½ƒNƒ‰ƒX
*/
class Input
{
public:
	Input();
	~Input();

	/**
	* @brief ˆÚ“®Œ³‚ÌY”Ô†“ü—ÍŠÖ”
	* ˆÚ“®‚³‚¹‚½‚¢‰~”Õ‚ª‚ ‚éY‚Ì”Ô†‚ğ“ü—Í‚·‚é
	*
	* @return “ü—Í‚µ‚½Y‚Ì”Ô†
	*/
	int SelectSourcePile();


	/**
	* @brief ˆÚ“®æ‚ÌY”Ô†“ü—ÍŠÖ”
	* 
	* @param source_pile_num@ˆÚ“®Œ³‚ÌY”Ô†
	* @return “ü—Í‚µ‚½Y”Ô†
	*/
	int SelectDestinationPile(int source_pile_num);

};

#endif


