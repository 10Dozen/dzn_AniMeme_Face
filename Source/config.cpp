class CfgPatches
{
	class dzn_AnimeFace
	{
		units[]={};
		weapons[]={
			"dzn_G_AnimeFace_Popuko"
			, "dzn_G_AnimeFace_Pipimi"
			, "dzn_G_AnimeFace_IDW"
			, "dzn_G_AnimeFace_Chen"
			, "dzn_G_AnimeFace_Kirima_Sharo"
			, "dzn_G_AnimeFace_Z1"
			, "dzn_G_AnimeFace_Prosecutor"
			, "dzn_G_AnimeFace_Yuuri"
			, "dzn_G_AnimeFace_Chito"
			, "dzn_G_AnimeFace_OperatorChan"
			, "dzn_G_AnimeFace_Yukari"
			, "dzn_G_AnimeFace_Liberator1"
			, "dzn_G_AnimeFace_Liberator2"
			, "dzn_G_AnimeFace_Novislav"
			, "dzn_G_AnimeFace_Merchant"
			, "dzn_G_AnimeFace_MuricanEbin"
			, "dzn_G_AnimeFace_Ebin"
			, "dzn_G_AnimeFace_SGM_Vining"
		};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","CBA_MAIN"};
		version=0.2
	};
};
class Headgear_Base_F;
class Item_Base_F;

#define AF_MACRO(NAME,TEXTURE,DOMAIN)	displayName = NAME; \
	picture = \dzn_AnimeFace\data\TEXTURE##_ca.paa; \
	hiddenSelectionsTextures[] = { \dzn_AnimeFace\data\TEXTURE##_ca.paa }; \
	scope = 2; \
	hiddenSelections[] = {"Camo"}; \
	domain = DOMAIN
	
	
class CfgGlasses
{
	class None;
	class dzn_AnimeFace: None
	{
		scope = 1;
		mass = 1;
		author = "10Dozen & Urban";
		displayName = "Anime Face";
		model = "\dzn_AnimeFace\AnimeFace.p3d";
		picture = "\dzn_AnimeFace\data\ui\IDWchan_UI.paa";
		identityTypes[] = {};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\dzn_AnimeFace\data\IDWchan_ca.paa"};
	};
	
	class dzn_G_AnimeFace_Popuko: dzn_AnimeFace { AF_MACRO("[AF] Popuko (Pop Team Epic)",popuko,"Anime") };
	class dzn_G_AnimeFace_Pipimi: dzn_AnimeFace { AF_MACRO("[AF] Pipimi (Pop Team Epic)",pipimi,"Anime") };	
	class dzn_G_AnimeFace_IDW: dzn_AnimeFace { AF_MACRO("[AF] IDW-chan (Girls' Frontline)",idwchan,"Anime") };
	class dzn_G_AnimeFace_Chen: dzn_AnimeFace { AF_MACRO("[AF] Chen (Touhou Project)",chen,"Anime") };
	class dzn_G_AnimeFace_Kirima_Sharo: dzn_AnimeFace { AF_MACRO("[AF] Kirima Sharo (lolicon hentai)",kirima_sharo,"Anime") };	
	class dzn_G_AnimeFace_Z1: dzn_AnimeFace { AF_MACRO("[AF] Z1 (Kancolle)",z1,"Anime") };
	class dzn_G_AnimeFace_Prosecutor: dzn_AnimeFace { AF_MACRO("[AF] Prosecutor",prosecutor,"Anime") };	
	class dzn_G_AnimeFace_Yuuri: dzn_AnimeFace { AF_MACRO("[AF] Yuuri (Shoujo Shuumatsu Ryokou)",yuuri,"Anime") };	
	class dzn_G_AnimeFace_Chito: dzn_AnimeFace { AF_MACRO("[AF] Chito (Shoujo Shuumatsu Ryokou)",chito,"Anime") };
	class dzn_G_AnimeFace_OperatorChan: dzn_AnimeFace { AF_MACRO("[AF] Operator Chan (/k)",operatorchan,"Anime") };
	class dzn_G_AnimeFace_Yukari: dzn_AnimeFace { AF_MACRO("[AF] Yukari (NVG) (Girls und Panzer)",yukari_NVG,"Anime") };
	
	class dzn_G_AnimeFace_Liberator1: dzn_AnimeFace { AF_MACRO("[AF] Liberator Ivan",liberator1,"Meme") };
	class dzn_G_AnimeFace_Liberator2: dzn_AnimeFace { AF_MACRO("[AF] Liberator Vasily",liberator2,"Meme") };	
	class dzn_G_AnimeFace_Novislav: dzn_AnimeFace { AF_MACRO("[AF] Novislav (Remove kebab)",novislav,"Meme") };
	class dzn_G_AnimeFace_Merchant: dzn_AnimeFace { AF_MACRO("[AF] Merchant",merchant,"Meme") };
	class dzn_G_AnimeFace_MuricanEbin: dzn_AnimeFace { AF_MACRO("[AF] Murican Ebin",muricanEbin,"Meme") };
	class dzn_G_AnimeFace_Ebin: dzn_AnimeFace { AF_MACRO("[AF] Ebin",ebin,"Meme") };
	class dzn_G_AnimeFace_SGM_Vining: dzn_AnimeFace { AF_MACRO("[AF] SGM M.Vining",k_vining,"Meme") };
	
};


class Extended_PostInit_EventHandlers
{
	class dzn_AnimeFace
	{
		init = call compile preprocessFileLineNumbers "\dzn_AnimeFace\Init.sqf";
	};
};