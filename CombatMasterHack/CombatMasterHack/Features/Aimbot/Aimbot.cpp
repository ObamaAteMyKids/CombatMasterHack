#include "../../Includes.hpp"
#define RADPI 57.295779513082f


void Aimbot::OnTick()
{
	if (!Menu::Vars::aimbot)
		return;

	if (!Hooks::Game::localPlayer) {
		Hooks::Game::allPlayers.clear();
		return;
	}

	if (Hooks::Game::localPlayer->GetPlayerHealth()->GetIsDead())
		return;

	if (Hooks::Game::allPlayers.empty())
		return;

	if (!GetAsyncKeyState(VK_LBUTTON))
		return;

	auto localPos = Hooks::Game::localPlayer->GetFPSPivot()->GetPosition();
	auto localForward = Hooks::Game::localPlayer->GetFPSPivot()->GetForward();
	auto localAngles = Hooks::Game::localPlayer->GetFPSPivot()->GetEulerAngles();

	for (const auto currentPlayer : Hooks::Game::allPlayers) {
		if (!currentPlayer)
			continue;

		if (!currentPlayer->GetIsVisible())
			continue;

		Vector3D enemyPos = currentPlayer->GetTransform()->GetPosition() + currentPlayer->GetHeadHitbox()->GetHitboxCenter();
		Vector3D direction = enemyPos - localPos;

		Vector3D aimAngle = UnityEngine::Quaternion::LookRotation(direction.Normalized()).GetEulerAngles();

		if (aimAngle.x > 180.f)
			aimAngle.y -= 360.f;

		aimAngle.z = localAngles.z;

		Hooks::Game::localPlayer->GetFPSPivot()->SetEulerAngles(aimAngle);
	}
}

void Aimbot::RunTeleportHack()
{
	if (!Menu::Vars::teleportPlayers)
		return;

	if (!Hooks::Game::localPlayer)
		return;

	if (Hooks::Game::localPlayer->GetPlayerHealth()->GetIsDead())
		return;

	if (Hooks::Game::allPlayers.empty())
		return;

	if (!GetAsyncKeyState('L'))
		return;

	for (auto currentPlayer : Hooks::Game::allPlayers) {

		if (currentPlayer->GetTeamID() == Hooks::Game::localPlayer->GetTeamID())
			continue;

		if (currentPlayer->GetPlayerHealth()->GetIsDead())
			continue;

		if (Hooks::Game::localPlayer->GetPlayerHealth()->GetIsDead())
			continue;

		//only works in local match, to make this work in multiplayer look at playercommand classes, not too difficult
		currentPlayer->GetTransform()->SetPosition(Hooks::Game::localPlayer->GetTransform()->GetPosition() + Hooks::Game::localPlayer->GetTransform()->GetForward() * 2);
	}
}