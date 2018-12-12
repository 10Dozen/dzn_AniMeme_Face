
dzn_fnc_AF_initFaces = {
	if (isNil "dzn_AF_Faces") then {
		dzn_AF_Faces = getArray(configFile >> "CfgPatches" >> "dzn_AnimeFace" >> "weapons");		
	};
	
	dzn_AF_Faces
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
			hint "[AF] New face set";
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

dzn_fnc_AF_applyRandomFaceToAllMissionUnits = {
	params ["_forced", ["_removeHMD", false]];
	
	hint "[AF] Randomizing faces...";
	{
		[_x, _forced, _removeHMD] spawn dzn_fnc_AF_applyRandomFace;
	} forEach allUnits;
	
	hint "[AF] Done!";
};


[] call dzn_fnc_AF_initFaces;

if !(hasInterface) exitWith {};

private _pattern = "<br />[ <font color='#A0DB65'><execute expression='[player, ""%2"", true] call dzn_fnc_AF_applyFace'>Get %1 face</execute></font> ]";
private _faceSelectionControls = "";

{
	private _btn = format [_pattern, getText(configFile >> "CfgGlasses" >> _x >> "displayName"), _x];
	_faceSelectionControls = _faceSelectionControls + _btn;
} forEach dzn_AF_Faces;

// ********** Topics ****************
#define NOTES		private["_topics"]; _topics = []; player createDiarySubject ["dzn_AF_Page","dzn Anime Faces"];
#define TOPIC(Y, NAME) 	if (Y) then { _topics pushBack ["dzn_AF_Page", [ NAME,
#define END			]]; };
#define ADD_TOPICS	for "_i" from (count _topics) to 0 step -1 do {player createDiaryRecord (_topics select _i);};

NOTES	

TOPIC(true, "[AF Player Controls]")
"
<br />[ <font color='#A0DB65'><execute expression='[player, true] call dzn_fnc_AF_applyRandomFace'>Get random face</execute></font> ] 
<br />" + _faceSelectionControls
END

TOPIC(true, "[AF Mission Controls]")
"<br />[<font color='#A0DB65'><execute expression='[false, false] call dzn_fnc_AF_applyRandomFaceToAllMissionUnits'>Apply to all units (not forced, save NVGs)</execute></font>]
<br />
<br />[<font color='#A0DB65'><execute expression='[true, false] call dzn_fnc_AF_applyRandomFaceToAllMissionUnits'>Apply to all units (forced, save NVGs)</execute></font>]
<br />
<br />[<font color='#A0DB65'><execute expression='[false, true] call dzn_fnc_AF_applyRandomFaceToAllMissionUnits'>Apply to all units (not forced, remove NVGs)</execute></font>]
<br />
<br />[<font color='#A0DB65'><execute expression='[true, true] call dzn_fnc_AF_applyRandomFaceToAllMissionUnits'>Apply to all units (forced, remove NVGs)</execute></font>]

"
END

ADD_TOPICS
