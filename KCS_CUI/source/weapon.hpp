﻿#pragma once
#include <iostream>
// 種別
enum WeaponClass {
	kWeaponClassGun, kWeaponClassAP, kWeaponClassSubGun, kWeaponClassTorpedo, kWeaponClassSpecialSS,			//特殊潜航艇まで
	kWeaponClassPF, kWeaponClassPB, kWeaponClassPBF, kWeaponClassWB, kWeaponClassPA, kWeaponClassPS,			//艦上偵察機まで
	kWeaponClassPSS, kWeaponClassDaiteiChan, kWeaponClassWS, kWeaponClassWSN, kWeaponClassASPP, kWeaponClassAJ,	//オートジャイロまで
	kWeaponClassSmallR, kWeaponClassLargeR, kWeaponClassAAG, kWeaponClassAAA, kWeaponClassAAD, kWeaponClassDP,	//爆雷まで
	kWeaponClassSonar, kWeaponClassDC, kWeaponClassSL, kWeaponClassLB, kWeaponClassHQ, kWeaponClassSSP,			//水上艦要員まで
	kWeaponClassCR, kWeaponClassOS, kWeaponClassOther
};
const vector<string> kWeaponClassStr = {
	"主砲", "対艦強化弾", "副砲", "魚雷", "特殊潜航艇", "艦上戦闘機", "艦上爆撃機","艦上爆撃機(爆戦)", "水上爆撃機",
	"艦上攻撃機", "艦上偵察機", "艦上偵察機(彩雲)", "大型飛行艇", "水上偵察機", "水上偵察機(夜偵)", "対潜哨戒機",
	"オートジャイロ", "小型電探","大型電探", "対空機銃", "対空強化弾", "高射装置", "爆雷", "ソナー", "応急修理要員",
	"探照灯", "照明弾", "艦隊司令部施設", "水上艦要員", "戦闘糧食", "洋上補給", "その他"
};

//装備クラス
class Weapon {
	int id_;					//装備ID
	wstring name_;				//装備名
	WeaponClass weapon_class_;	//種別
	int defense_;				//装甲
	int attack_;				//火力
	int torpedo_;				//雷撃
	int bomb_;					//爆装
	int anti_air_;				//対空
	int anti_sub_;				//対潜
	int hit_;					//命中
	int evade_;					//回避
	int search_;				//索敵
	Range range_;				//射程
	int level_;					//装備改修度(0-10)、外部熟練度(0-7)
	int level_detail_;			//内部熟練度(0-120)
public:
	// コンストラクタ
	Weapon() noexcept;
	Weapon(
		const int, wstring, const WeaponClass, const int, const int, const int, const int,
		const int, const int, const int, const int, const int, const Range, const int, const int) noexcept;
	// getter
	const std::wstring& GetName() const noexcept;
	WeaponClass GetWeaponClass() const noexcept;
	int GetDefense() const noexcept;
	int GetTorpedo() const noexcept;
	int GetBomb() const noexcept;
	int GetAntiAir() const noexcept;
	int GetHit() const noexcept;
	int GetEvade() const noexcept;
	int GetSearch() const noexcept;
	Range GetRange() const noexcept;
	int GetLevel() const noexcept;
	// setter
	void SetLevel(const int level);
	void SetLevelDetail(const int level_detail);
	// その他
	void Put() const;					//中身を表示する
	int AntiAirScore(const int&) const noexcept;	//制空値を計算する
	bool IsAir() const noexcept;					//(熟練度が存在する)艦載機ならtrue
	bool IsAirFight() const noexcept;				//航空戦に参加する艦載機ならtrue
	bool IsAirTrailer() const noexcept;				//触接に参加する艦載機ならtrue
	bool IsAirBomb() const noexcept;				//開幕爆撃に参加する艦載機ならtrue
	bool IsHAG() const noexcept;					//高角砲ならtrue
	bool Include(const wstring&) const noexcept;	//名前に特定の文字が含まれていればtrue
	friend std::ostream& operator<<(std::ostream& os, const Weapon& conf);
	friend std::wostream& operator<<(std::wostream& os, const Weapon& conf);
};
std::ostream& operator<<(std::ostream& os, const Weapon& conf);
std::wostream& operator<<(std::wostream& os, const Weapon& conf);

// 文字列を種別に変換する
WeaponClass ToWC(const string);

// 外部熟練度(Simple)を内部熟練度(Detail)に変換する
int ConvertStoD(const int&);

// 内部熟練度を外部熟練度に変換する
int ConvertDtoS(const int&);
