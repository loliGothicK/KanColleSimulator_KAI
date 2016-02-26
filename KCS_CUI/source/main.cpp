/* KanColleSimulator Ver.1.0 */

#include "base.hpp"
#include "config.hpp"
#include "weapon.hpp"
#include "kammusu.hpp"
#include "other.hpp"

int main(int argc, char *argv[]) {
	try {
		// 現在の設定を取得する
		Config config(argc, argv);
		config.Put();
		// データベースを読み込む
		WeaponDB weapon_db;
		weapon_db.Get(-1).Put();
		weapon_db.Get(1).Put();
		KammusuDB kammusu_db;
		kammusu_db.Get(-1, 1).Reset().Put();
		kammusu_db.Get(1, 1).Reset().Put();
//		kammusu_db.Get(1, 1).Reset(weapon_db).Put();
		kammusu_db.Get(1, 99).Reset().Put();
		kammusu_db.Get(1, 155).Reset().Put();
	}
	catch (char *e) {
		std::cerr << "エラー：" << e << std::endl;
	}
	return 0;
}
