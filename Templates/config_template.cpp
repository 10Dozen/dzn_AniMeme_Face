class CfgPatches
{
	class YOUR_MOD_CLASSNAME
	{
		units[]={};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","CBA_MAIN","dzn_AniMemeFace"};
	};
};
class Headgear_Base_F;
class Item_Base_F;

#define AF_MACRO(NAME,TEXTURE,DOMAIN) \
	class dzn_G_AniMemeFace_##TEXTURE : dzn_AniMemeFace \
	{ \
		displayName = NAME; \
		picture = \dzn_AniMemeFace\data\TEXTURE##_ca.paa; \
		hiddenSelectionsTextures[] = { \dzn_AniMemeFace\data\TEXTURE##_ca.paa }; \
		scope = 2; \
		hiddenSelections[] = {"Camo"}; \
		domain = DOMAIN \
		author = "AniMeme Faces"; \
	};

class CfgGlasses
{
	class None;
	class dzn_AniMemeFace;

	/*
		DISPLAY_NAME -- name of the item in arsenal/inventory
		IMAGE_NAME -- part of image file name without tailing '_ca.paa' (e.g. for 'my_face_ca.paa' -> 'my_face')
		DOMAIN_NAME -- some meta info about what kind of face is your item
		
		Your new classname will be generated as 'dzn_G_AniMemeFace_IMAGE_NAME'
	*/
	AF_MACRO(DISPLAY_NAME,IMAGE_NAME,DOMAIN_NAME)	
	// AF_MACRO("[AF] Pipimi (Pop Team Epic)",pipimi,"Anime")
	
};
