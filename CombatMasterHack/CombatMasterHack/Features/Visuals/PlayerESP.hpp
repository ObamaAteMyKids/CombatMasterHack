#pragma once

struct Box
{
	int x = 0;
	int y = 0;
	int w = 0;
	int h = 0;
};

namespace PlayerESP
{
	void OnRender();
	void GetBoundingBox(PlayerRoot* player, Box& box);

	namespace Features
	{
		void BoxEsp(PlayerRoot* player, Box& box);
		void HealthEsp(PlayerRoot* player, Box& box);
		void FlagEsp(PlayerRoot* player, Box& box);
		void WeaponEsp(PlayerRoot* player, Box& box);
		void NameEsp(PlayerRoot* player, Box& box);
	}
}