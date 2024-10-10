#include "mod/FuckZombifiedPiglin.h"

#include <memory>

#include "ll/api/memory/Hook.h"
#include "ll/api/mod/NativeMod.h"
#include "ll/api/mod/RegisterHelper.h"
#include "mc/world/actor/common/SpawnChecks.h"


LL_AUTO_STATIC_HOOK(
    ZombifiedPiglinSpawnFromPortalCheckHook,
    ll::memory::HookPriority::Normal,
    "?canSpawnPigZombieFromPortal@SpawnChecks@@SA_NAEBVDimension@@AEBVRandomize@@@Z",
    bool,
    class Dimension const& dimension,
    class Randomize const& randomize
) {
    origin(dimension, randomize);
    return false;
};

namespace fuckzombifiedpiglin {

static std::unique_ptr<FuckZombifiedPiglin> instance;

FuckZombifiedPiglin& FuckZombifiedPiglin::getInstance() { return *instance; }

bool FuckZombifiedPiglin::load() {
    getSelf().getLogger().info("Loading...");
    // Code for loading the mod goes here.
    return true;
}

bool FuckZombifiedPiglin::enable() {
    getSelf().getLogger().info("Enabling...");
    // Code for enabling the mod goes here.
    return true;
}

bool FuckZombifiedPiglin::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the mod goes here.
    return true;
}

} // namespace fuckzombifiedpiglin

LL_REGISTER_MOD(fuckzombifiedpiglin::FuckZombifiedPiglin, fuckzombifiedpiglin::instance);
