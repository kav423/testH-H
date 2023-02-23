#pragma once

class enemy
{
protected:
	int attack_h = rand(21)+1;
	int protection_h = rand(21)+1;
	int health_h = rand(n+1);
	int healing_h = n/2;
	int heal_h = 3;
	int damage_h = rand(m+1)+n;
	int attack_m = rand(21) + 1;
	int protection_m = rand(21) + 1;
	int health_m = rand(n + 1);
	int damage_m = rand(m + 1) + n;
	int even = 1;
	int mod_attack;
	int a, b;

	void parametrs() {
		if (even % 2 == 1) {
			mod_attack = attack_h - protection_m + 1;
			for (int i = 1; i < mod_attack; i++) {
				a = rand(7) + 1;
				if (a >= 5) {
					health_m = health_m - damage_h;
				}
			}
		}
		else {
			mod_attack = attack_m - protection_h + 1;
			for (int i = 1; i < mod_attack; i++) {
				a = rand(7) + 1;
				if (a >= 5) {
					health_h = health_h - damage_m;
				}
			}
		}
		if ((health_h == 0) || (health_m == 0)) {
			break;
		}
		else {
			continue;
		}
	}
};

class hero : public enemy {
public:
	void attack_h() {
		if (even % 2 == 1) {
			parametrs();
		}
	}
};

class monster : public enemy {
public:
	void attack_m() {
		if (even % 2 == 0) {
			parametrs();
		}
	}
};
