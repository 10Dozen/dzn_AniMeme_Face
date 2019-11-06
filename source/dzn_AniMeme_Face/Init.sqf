
dzn_fnc_AF_initFaces = {
	if (isNil "dzn_AF_Faces") then {
		dzn_AF_Faces = getArray(configFile >> "dzn_AniMemeFaces" >> "faces");
		
		dzn_AF_Domains = [];
		{
			private _domain = getText (configFile >> "CfgGlasses" >> _x >> "domain");
			private _domainVar = format ["dzn_AF__%1", _domain];

			if (isNil _domainVar) then {
				dzn_AF_Domains pushBackUnique _domain;
				missionNamespace setVariable [_domainVar, [_x]];
			} else {
				(missionNamespace getVariable _domainVar) pushBack _x;
			};
		} forEach dzn_AF_Faces;
	};
	
	(true)
};

dzn_fnc_AF_applyFace = {
	params ["_unit", "_face", "_forced", "_removeHMD"];
	
	if (!_forced && _unit getVariable ["dzn_AF_FaceAdded", false]) exitWith {}; // Exit if not forced and already has
	
	if (local _unit) then {
		removeGoggles _unit;
		_unit addGoggles _face;
		_unit setVariable ["dzn_AF_FaceAdded", true, true];
		
		if (_removeHMD && !isPlayer _unit) then {
			private _item = hmd _unit;
			_unit unassignItem _item;
			_unit removeItem _item;
		};
		
		if (isPlayer _unit) then {
			hint parseText format [
				"[AF] New face set<br/><img size='10' image='%1'/><br/>%2"
				,getText(configFile >> "CfgGlasses" >> _face >> "picture") 
				,getText(configFile >> "CfgGlasses" >> _face >> "displayName")
			];
		};
	} else {
		_this remoteExec ["dzn_fnc_AF_applyFace", _unit];
	};
};

dzn_fnc_AF_applyRandomFace = {
	params ["_unit", ["_forced", false], ["_removeHMD", false]];
	if (isNil "dzn_AF_Faces") then { [] call dzn_fnc_AF_initFaces; };
	
	[_unit, selectRandom dzn_AF_Faces, _forced, _removeHMD] call dzn_fnc_AF_applyFace;
};

dzn_fnc_AF_applyRandomFaceByDomain = {
	params ["_unit", "_domain", ["_forced", false], ["_removeHMD", false]];
	if (isNil "dzn_AF_Faces") then { [] call dzn_fnc_AF_initFaces; };

	private _faces = (missionNamespace getVariable format ["dzn_AF__%1", _domain]);
	if (_faces isEqualTo []) exitWith { hint "No faces in selected domain!"; };

	[_unit, selectRandom _faces, _forced, _removeHMD] call dzn_fnc_AF_applyFace;
};

dzn_fnc_AF_applyRandomFaceToAllMissionUnits = {
	params ["_forced", ["_removeHMD", false]];
	
	hint "[AF] Randomizing faces...";
	{
		[_x, _forced, _removeHMD] spawn dzn_fnc_AF_applyRandomFace;
	} forEach allUnits;
	
	hint "[AF] Done!";
};


// --------------
// Initialization
// --------------

[] call dzn_fnc_AF_initFaces;

if !(hasInterface) exitWith {};

dzn_fnc_AF_addTopic = {
	private _diaryPage = "dzn_AF_Page";
	if (player diarySubjectExists _diaryPage) exitWith {};
	
	private _fnc_trim = { _this splitString toString[9, 13, 10] joinString "" };
	
	// Random in domain select buttons
	private _randomByDomainControl = "";
	{
		private _btn = format [
			"<br />[ <font color='#A0DB65'><execute expression='[player, ""%1"", true] call %2'>Get random %1 face</execute></font> ]"
			, _x
			, "dzn_fnc_AF_applyRandomFaceByDomain"
		];
		_randomByDomainControl = _randomByDomainControl + _btn;
	} forEach dzn_AF_Domains;

	// Face select buttons
	private _faceSelectionControls = "";
	{ 
		private _btn = format [ 
			"<execute expression='[player, ""%2"", true] call dzn_fnc_AF_applyFace'><img image='%1' width='64px' />Get</execute>" 
			, getText(configFile >> "CfgGlasses" >> _x >> "picture") 
			, _x 
		]; 
		_faceSelectionControls = _faceSelectionControls + _btn; 
	} forEach dzn_AF_Faces;
	
	private _AF_Player_Topic = "<br />[ <font color='#A0DB65'><execute expression='[player, true] call dzn_fnc_AF_applyRandomFace'>Get random face</execute></font> ]<br />" + _randomByDomainControl + "<br /><br />" + _faceSelectionControls;
	private _AF_Mission_Topic = format [
		"<br />[<font color='#A0DB65'><execute expression='[false, false] call %1'>Apply to all units (not forced, save NVGs)</execute></font>]
		<br /><br />[<font color='#A0DB65'><execute expression='[true, false] call %1'>Apply to all units (forced, save NVGs)</execute></font>]
		<br /><br />[<font color='#A0DB65'><execute expression='[false, true] call %1'>Apply to all units (not forced, remove NVGs)</execute></font>]
		<br /><br />[<font color='#A0DB65'><execute expression='[true, true] call %1'>Apply to all units (forced, remove NVGs)</execute></font>]
		"
		, "dzn_fnc_AF_applyRandomFaceToAllMissionUnits"
	];
	
	player createDiarySubject [_diaryPage,"dzn AniMeme Faces"];
	player createDiaryRecord [ _diaryPage, ["[AF Mission Controls]", _AF_Mission_Topic call _fnc_trim] ];
	player createDiaryRecord [ _diaryPage, ["[AF Player Controls]", _AF_Player_Topic] ];
};

[{ [] call dzn_fnc_AF_addTopic; }, 60, []] call CBA_fnc_addPerFrameHandler;
