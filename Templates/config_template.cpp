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

/*
	Update "picture" and "hiddenSelectionsTextures" path with your mod path!
*/
#define AF_MACRO(NAME,TEXTURE,DOMAIN) \
	class dzn_G_AniMemeFace_##TEXTURE : dzn_AniMemeFace \
	{ \
		displayName = NAME; \
		picture = \YOUR_MOD_PATH\TEXTURE##_ca.paa; \
		hiddenSelectionsTextures[] = { \YOUR_MOD_PATH\TEXTURE##_ca.paa }; \
		scope = 2; \
		hiddenSelections[] = {"Camo"}; \
		domain = DOMAIN \
		author = "YOUR NAME"; \
	};
	
class CfgGlasses
{
	class None;
	class dzn_AniMemeFace;

	/*
		Define your classes here, using AF_MACRO macros:
		
		DISPLAY_NAME -- name of the item in arsenal/inventory
		IMAGE_NAME -- part of image file name without tailing '_ca.paa' (e.g. for 'my_face_ca.paa' -> 'my_face')
		DOMAIN_NAME -- some meta info about what kind of face is your item
		
		Your new classname will be generated as 'dzn_G_AniMemeFace_IMAGE_NAME'
		No spaces should be left before and after comma!
		
		Example:
		AF_MACRO("[AF] Pipimi (Pop Team Epic)",pipimi,"Anime")
		
		will create 'dzn_G_AniMemeFace_pipimi' class, that use 'pipimi_ca.paa' image
	*/
	
	AF_MACRO(MY_DISPLAY_NAME,MY_IMAGE_NAME,MY_DOMAIN_NAME)
};

class dzn_AniMemeFaces
{
	/*
		Add your new classes here to make them visible from map menu
		
		You can AF_CLASS(IMAGE_NAME) macro to generate classname, e.g. AF_CLASS(pipimi) -> dzn_G_AniMemeFace_pipimi
		
	*/
	#define AF_CLASS(TEXTURE) dzn_G_AniMemeFace_##TEXTURE
	faces[] += {
		MY_CLASSNAME_1
		, AF_CLASS(MY_IMAGE_NAME)
	};
};
