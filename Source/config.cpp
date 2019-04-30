class CfgPatches
{
	class dzn_AniMemeFace
	{
		units[]={};
		weapons[]={
			dzn_G_AniMemeFace_Popuko
			, dzn_G_AniMemeFace_Pipimi
			, dzn_G_AniMemeFace_IDW
			, dzn_G_AniMemeFace_megumin			
			, dzn_G_AniMemeFace_Shoebill
			, dzn_G_AniMemeFace_Kirima_Sharo
			, dzn_G_AniMemeFace_Prosecutor
			, dzn_G_AniMemeFace_OperatorChan
			, dzn_G_AniMemeFace_Yukari_NVG
			, dzn_G_AniMemeFace_Yuuri
			, dzn_G_AniMemeFace_Chito			
			, dzn_G_AniMemeFace_Chen
			, dzn_G_AniMemeFace_Cirno
			, dzn_G_AniMemeFace_youmu_konpaku
			, dzn_G_AniMemeFace_momiji_inubashiri
			, dzn_G_AniMemeFace_Z1
			, dzn_G_AniMemeFace_Z3
			, dzn_G_AniMemeFace_ikazuchi_kancolle
			, dzn_G_AniMemeFace_kiso_kancolle
			, dzn_G_AniMemeFace_yukikaze_kancolle
			, dzn_G_AniMemeFace_zuikaku_kancolle
			, dzn_G_AniMemeFace_liberator1
			, dzn_G_AniMemeFace_liberator2
			, dzn_G_AniMemeFace_novislav
			, dzn_G_AniMemeFace_merchant
			, dzn_G_AniMemeFace_muricanEbin
			, dzn_G_AniMemeFace_ebin
			, dzn_G_AniMemeFace_k_vining
			, dzn_G_AniMemeFace_alex_jones
			, dzn_G_AniMemeFace_alex_jones_1776
			, dzn_G_AniMemeFace_guba_general
			, dzn_G_AniMemeFace_guba
			, dzn_G_AniMemeFace_impossibiru
			, dzn_G_AniMemeFace_feel
			, dzn_G_AniMemeFace_boomer
			, dzn_G_AniMemeFace_boomer_shades
			, dzn_G_AniMemeFace_zoomer
			, dzn_G_AniMemeFace_pepe_happy
			, dzn_G_AniMemeFace_pepe_angry
			, dzn_G_AniMemeFace_pepe_islamic
			, dzn_G_AniMemeFace_pepe_operator
			, dzn_G_AniMemeFace_yoba
			, dzn_G_AniMemeFace_yoba_serbian
			, dzn_G_AniMemeFace_yoba_islamic
			, dzn_G_AniMemeFace_yoba_operator
			, dzn_G_AniMemeFace_yoba_oldfag
			, dzn_G_AniMemeFace_yoba_officer
			, dzn_G_AniMemeFace_trollface
			, dzn_G_AniMemeFace_shrek
			, dzn_G_AniMemeFace_guardsman
			, dzn_G_AniMemeFace_commissar
			, dzn_G_AniMemeFace_techpriest
			, dzn_G_AniMemeFace_necron
		};
		requiredVersion=0.1;
		requiredAddons[]={"A3_Data_F","CBA_MAIN"};
		version=0.5
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
	};
	
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
	
	AF_MACRO("[AF] Popuko (Pop Team Epic)",popuko,"Anime")
	AF_MACRO("[AF] Pipimi (Pop Team Epic)",pipimi,"Anime")
	
	AF_MACRO("[AF] IDW-chan (Girls' Frontline)",idwchan,"Anime")
	AF_MACRO("[AF] Megumin (KonoSuba)",megumin,"Anime")
	AF_MACRO("[AF] Shoebill (Kemono Friends)",shoebill,"Anime")
	AF_MACRO("[AF] Kirima Sharo (lolicon hentai)",kirima_sharo,"Anime")	
	AF_MACRO("[AF] Prosecutor",prosecutor,"Anime")
	AF_MACRO("[AF] Operator Chan (/k)",operatorchan,"Anime")
	AF_MACRO("[AF] Yukari (NVG) (Girls und Panzer)",yukari_NVG,"Anime")
	AF_MACRO("[AF] Yuuri (Shoujo Shuumatsu Ryokou)",yuuri,"Anime")
	AF_MACRO("[AF] Chito (Shoujo Shuumatsu Ryokou)",chito,"Anime")
	
	AF_MACRO("[AF] Chen (Touhou Project)",chen,"Anime")
	AF_MACRO("[AF] Cirno (Touhou Project)",cirno,"Anime")
	AF_MACRO("[AF] Youmu Konpaku (Touhou Project)",youmu_konpaku,"Anime")
	AF_MACRO("[AF] Momiji Inubashiri (Touhou Project)",momiji_inubashiri,"Anime")
	
	AF_MACRO("[AF] Z1 (Kancolle)",z1,"Anime")
	AF_MACRO("[AF] Z3 (Kancolle)",z3,"Anime")
	AF_MACRO("[AF] Ikazuchi (Kancolle)",ikazuchi_kancolle,"Anime")
	AF_MACRO("[AF] Kiso (Kancolle)",kiso_kancolle,"Anime")
	AF_MACRO("[AF] Yukikaze (Kancolle)",yukikaze_kancolle,"Anime")
	AF_MACRO("[AF] Zuikaku (Kancolle)",zuikaku_kancolle,"Anime")
		
	AF_MACRO("[AF] Liberator Ivan",liberator1,"Meme")
	AF_MACRO("[AF] Liberator Vasily",liberator2,"Meme")	
	AF_MACRO("[AF] Novislav (Remove kebab)",novislav,"Meme")
	AF_MACRO("[AF] Merchant",merchant,"Meme")
	AF_MACRO("[AF] Murican Ebin",muricanEbin,"Meme")
	AF_MACRO("[AF] Ebin",ebin,"Meme")
	AF_MACRO("[AF] SGM M.Vining",k_vining,"Meme")
	AF_MACRO("[AF] Alex Jones",alex_jones,"Meme")
	AF_MACRO("[AF] Alex Jones (tfw 1776 has commenced)",alex_jones_1776,"Meme")
	AF_MACRO("[AF] General Guba",guba_general,"Meme")
	AF_MACRO("[AF] Colonel Guba",guba,"Meme")
	AF_MACRO("[AF] Pvt. Impossibiru",impossibiru,"Meme")
	
	AF_MACRO("[AF] Feel",feel,"Meme")
	AF_MACRO("[AF] Boomer",boomer,"Meme")
	AF_MACRO("[AF] Boomer (Shades)",boomer_shades,"Meme")
	AF_MACRO("[AF] Zoomer",zoomer,"Meme")
	AF_MACRO("[AF] Pepe (Happy)",pepe_happy,"Meme")
	AF_MACRO("[AF] Pepe (Angry)",pepe_angry,"Meme")
	AF_MACRO("[AF] Pepe (Islamic)",pepe_islamic,"Meme")
	AF_MACRO("[AF] Pepe (Operator)",pepe_operator,"Meme")
	AF_MACRO("[AF] Yoba",yoba,"Meme")
	AF_MACRO("[AF] Yoba (Serbian)",yoba_serbian,"Meme")
	AF_MACRO("[AF] Yoba (Islamic)",yoba_islamic,"Meme")
	AF_MACRO("[AF] Yoba (Operator)",yoba_operator,"Meme")
	AF_MACRO("[AF] Yoba (Oldfag)",yoba_oldfag,"Meme")
	AF_MACRO("[AF] Yoba (Officer)",yoba_officer,"Meme")
	AF_MACRO("[AF] Trollface",trollface,"Meme")
	AF_MACRO("[AF] Shrek",shrek,"Meme")
	
	AF_MACRO("[AF] Guardsman (WH40K)",guardsman,"WH40K")
	AF_MACRO("[AF] Commissar (WH40K)",commissar,"WH40K")
	AF_MACRO("[AF] Techpriest (WH40K)",techpriest,"WH40K")
	AF_MACRO("[AF] Necron (WH40K)",necron,"WH40K")
};


class Extended_PostInit_EventHandlers
{
	class dzn_AniMemeFace
	{
		init = call compile preprocessFileLineNumbers "\dzn_AniMemeFace\Init.sqf";
	};
};