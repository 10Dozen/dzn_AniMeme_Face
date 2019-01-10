class CfgPatches
{
	class dzn_AniMemeFace
	{
		units[]={};
		weapons[]={
			"dzn_G_AniMemeFace_Popuko"
			, "dzn_G_AniMemeFace_Pipimi"
			, "dzn_G_AniMemeFace_IDW"
			, "dzn_G_AniMemeFace_Chen"
			, "dzn_G_AniMemeFace_Cirno"
			, "dzn_G_AniMemeFace_Momiji"
			, "dzn_G_AniMemeFace_Kirima_Sharo"
			, "dzn_G_AniMemeFace_Z1"
			, "dzn_G_AniMemeFace_Z3"
			, "dzn_G_AniMemeFace_Prosecutor"
			, "dzn_G_AniMemeFace_Yuuri"
			, "dzn_G_AniMemeFace_Chito"
			, "dzn_G_AniMemeFace_OperatorChan"
			, "dzn_G_AniMemeFace_Yukari"
			, "dzn_G_AniMemeFace_Liberator1"
			, "dzn_G_AniMemeFace_Liberator2"
			, "dzn_G_AniMemeFace_Novislav"
			, "dzn_G_AniMemeFace_Merchant"
			, "dzn_G_AniMemeFace_MuricanEbin"
			, "dzn_G_AniMemeFace_Ebin"
			, "dzn_G_AniMemeFace_SGM_Vining"
			, "dzn_G_AniMemeFace_Pepe_Happy"
			, "dzn_G_AniMemeFace_Pepe_Angry"
			, "dzn_G_AniMemeFace_Pepe_Islamic"
			, "dzn_G_AniMemeFace_Pepe_Operator"
			, "dzn_G_AniMemeFace_Yoba"
			, "dzn_G_AniMemeFace_Yoba_Serbian"
			, "dzn_G_AniMemeFace_Yoba_Islamic"
			, "dzn_G_AniMemeFace_Yoba_Operator"
		};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","CBA_MAIN"};
		version=0.2
	};
};
class Headgear_Base_F;
class Item_Base_F;

#define AF_MACRO(NAME,TEXTURE,DOMAIN)	displayName = NAME; \
	picture = \dzn_AniMemeFace\data\TEXTURE##_ca.paa; \
	hiddenSelectionsTextures[] = { \dzn_AniMemeFace\data\TEXTURE##_ca.paa }; \
	scope = 2; \
	hiddenSelections[] = {"Camo"}; \
	domain = DOMAIN
	
	
class CfgGlasses
{
	class None;
	class dzn_AniMemeFace: None
	{
		scope = 1;
		mass = 1;
		author = "10Dozen & Urban";
		displayName = "AniMeme Face";
		model = "\dzn_AniMemeFace\AniMemeFace.p3d";
		picture = "\dzn_AniMemeFace\data\idwchan_ca.paa";
		identityTypes[] = {};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\dzn_AniMemeFace\data\idwchan_ca.paa"};
	};
	
	class dzn_G_AniMemeFace_Popuko: dzn_AniMemeFace { AF_MACRO("[AF] Popuko (Pop Team Epic)",popuko,"Anime") };
	class dzn_G_AniMemeFace_Pipimi: dzn_AniMemeFace { AF_MACRO("[AF] Pipimi (Pop Team Epic)",pipimi,"Anime") };	
	class dzn_G_AniMemeFace_IDW: dzn_AniMemeFace { AF_MACRO("[AF] IDW-chan (Girls' Frontline)",idwchan,"Anime") };
	class dzn_G_AniMemeFace_Chen: dzn_AniMemeFace { AF_MACRO("[AF] Chen (Touhou Project)",chen,"Anime") };
	class dzn_G_AniMemeFace_Cirno: dzn_AniMemeFace { AF_MACRO("[AF] Cirno (Touhou Project)",cirno,"Anime") };
	class dzn_G_AniMemeFace_Momiji: dzn_AniMemeFace { AF_MACRO("[AF] Momiji Inubashiri (Touhou Project)",momiji_inubashiri,"Anime") };
	
	class dzn_G_AniMemeFace_Kirima_Sharo: dzn_AniMemeFace { AF_MACRO("[AF] Kirima Sharo (lolicon hentai)",kirima_sharo,"Anime") };	
	class dzn_G_AniMemeFace_Z1: dzn_AniMemeFace { AF_MACRO("[AF] Z1 (Kancolle)",z1,"Anime") };
	class dzn_G_AniMemeFace_Z3: dzn_AniMemeFace { AF_MACRO("[AF] Z3 (Kancolle)",z3,"Anime") };
	class dzn_G_AniMemeFace_Prosecutor: dzn_AniMemeFace { AF_MACRO("[AF] Prosecutor",prosecutor,"Anime") };	
	class dzn_G_AniMemeFace_Yuuri: dzn_AniMemeFace { AF_MACRO("[AF] Yuuri (Shoujo Shuumatsu Ryokou)",yuuri,"Anime") };	
	class dzn_G_AniMemeFace_Chito: dzn_AniMemeFace { AF_MACRO("[AF] Chito (Shoujo Shuumatsu Ryokou)",chito,"Anime") };
	class dzn_G_AniMemeFace_OperatorChan: dzn_AniMemeFace { AF_MACRO("[AF] Operator Chan (/k)",operatorchan,"Anime") };
	class dzn_G_AniMemeFace_Yukari: dzn_AniMemeFace { AF_MACRO("[AF] Yukari (NVG) (Girls und Panzer)",yukari_NVG,"Anime") };
	
	class dzn_G_AniMemeFace_Liberator1: dzn_AniMemeFace { AF_MACRO("[AF] Liberator Ivan",liberator1,"Meme") };
	class dzn_G_AniMemeFace_Liberator2: dzn_AniMemeFace { AF_MACRO("[AF] Liberator Vasily",liberator2,"Meme") };	
	class dzn_G_AniMemeFace_Novislav: dzn_AniMemeFace { AF_MACRO("[AF] Novislav (Remove kebab)",novislav,"Meme") };
	class dzn_G_AniMemeFace_Merchant: dzn_AniMemeFace { AF_MACRO("[AF] Merchant",merchant,"Meme") };
	class dzn_G_AniMemeFace_MuricanEbin: dzn_AniMemeFace { AF_MACRO("[AF] Murican Ebin",muricanEbin,"Meme") };
	class dzn_G_AniMemeFace_Ebin: dzn_AniMemeFace { AF_MACRO("[AF] Ebin",ebin,"Meme") };
	class dzn_G_AniMemeFace_SGM_Vining: dzn_AniMemeFace { AF_MACRO("[AF] SGM M.Vining",k_vining,"Meme") };
	
	class dzn_G_AniMemeFace_Pepe_Happy: dzn_AniMemeFace { AF_MACRO("[AF] Pepe (Happy)",pepe_happy,"Meme") };
	class dzn_G_AniMemeFace_Pepe_Angry: dzn_AniMemeFace { AF_MACRO("[AF] Pepe (Angry)",pepe_angry,"Meme") };
	class dzn_G_AniMemeFace_Pepe_Islamic: dzn_AniMemeFace { AF_MACRO("[AF] Pepe (Islamic)",pepe_islamic,"Meme") };
	class dzn_G_AniMemeFace_Pepe_Operator: dzn_AniMemeFace { AF_MACRO("[AF] Pepe (Operator)",pepe_operator,"Meme") };
	class dzn_G_AniMemeFace_Yoba: dzn_AniMemeFace { AF_MACRO("[AF] Yoba",yoba,"Meme") };
	class dzn_G_AniMemeFace_Yoba_Serbian: dzn_AniMemeFace { AF_MACRO("[AF] Yoba (Serbian)",yoba_serbian,"Meme") };
	class dzn_G_AniMemeFace_Yoba_Islamic: dzn_AniMemeFace { AF_MACRO("[AF] Yoba (Islamic)",yoba_islamic,"Meme") };
	class dzn_G_AniMemeFace_Yoba_Operator: dzn_AniMemeFace { AF_MACRO("[AF] Yoba (Operator)",yoba_operator,"Meme") };
};


class Extended_PostInit_EventHandlers
{
	class dzn_AniMemeFace
	{
		init = call compile preprocessFileLineNumbers "\dzn_AniMemeFace\Init.sqf";
	};
};