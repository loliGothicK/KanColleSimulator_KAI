#pragma once

// íÊ
enum WeaponClass {
	kWeaponClassGun, kWeaponClassAP, kWeaponClassSubGun, kWeaponClassTorpedo, kWeaponClassSpecialSS,
	kWeaponClassPF, kWeaponClassPB, kWeaponClassPBF, kWeaponClassWB, kWeaponClassPA, kWeaponClassPS,
	kWeaponClassPSS, kWeaponClassDaiteiChan, kWeaponClassWS, kWeaponClassWSN, kWeaponClassASPP, kWeaponClassAJ,
	kWeaponClassSmallR, kWeaponClassLargeR, kWeaponClassAAG, kWeaponClassAAA, kWeaponClassAAD, kWeaponClassDP,
	kWeaponClassSonar, kWeaponClassDC, kWeaponClassSL, kWeaponClassLB, kWeaponClassHQ, kWeaponClassSSP,
	kWeaponClassCR, kWeaponClassOS, kWeaponClassOther
};
const vector<string> kWeaponClassStr = {
	"åC", "ÎÍ­»e", "C", "", "Áêöqø", "Íãí¬@", "Íã@","Íã@(í)", "ã@",
	"ÍãU@", "Íãã@@", "Íãã@@(Ê_)", "å^òsø", "ãã@@", "ãã@@(éã)", "Îö£ú@",
	"I[gWC", "¬^dT","å^dT", "Îó@e", "Îó­»e", "Ëu", "", "\i[", "}Cvõ",
	"TÆ", "Æ¾e", "Íàiß{Ý", "ãÍvõ", "í¬ÆH", "mãâ", "»Ì¼"
};

//õNX
class Weapon {
	int id_;					//õID
	string name_;				//õ¼
	WeaponClass weapon_class_;	//íÊ
	int defense_;				//b
	int attack_;				//ÎÍ
	int torpedo_;				//
	int bomb_;					//
	int anti_air_;				//Îó
	int anti_sub_;				//Îö
	int hit_;					//½
	int evade_;					//ñð
	int search_;				//õG
	Range range_;				//Ëö
	int level_;					//õüCx(0-10)Aànûx(0-120)
public:
	// RXgN^
	Weapon();
	Weapon(
		const int, const string, const WeaponClass, const int, const int, const int, const int,
		const int, const int, const int, const int, const int, const Range, const int);
	// gð\¦·é
	void Put();
	// getter
	string Name() { return name_; }
};

// ¶ñðíÊÉÏ··é
WeaponClass ToWC(const string);
