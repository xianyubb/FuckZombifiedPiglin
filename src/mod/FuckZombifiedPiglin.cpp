#include "mod/FuckZombifiedPiglin.h"

#include <memory>

#include "ll/api/mod/RegisterHelper.h"

#include "ll/api/memory/Hook.h"
#include "ll/api/mod/NativeMod.h"
#include "ll/api/mod/RegisterHelper.h"
#include "mc/world/actor/SpawnChecks.h"

#include "mc/world/level/block/PortalBlock.h"


// LL_AUTO_STATIC_HOOK(
//     ZombifiedPiglinSpawnFromPortalCheckHook,
//     ll::memory::HookPriority::Normal,
//     &SpawnChecks::canSpawnPigZombieFromPortal,
//     bool,
//     class Dimension const& dimension,
//     class Randomize const& randomize
// ) {
//     origin(dimension, randomize);
//     return false;
// };

LL_AUTO_STATIC_HOOK(
    TrySpawnPigZombieHook,
    ll::memory::HookPriority::Normal,
    &PortalBlock::trySpawnPigZombie,
    void,
    ::BlockSource&,
    ::BlockPos const&,
    ::PortalAxis
) {
    return;
}

namespace fuckzombifiedpiglin {


FuckZombifiedPiglin& FuckZombifiedPiglin::getInstance() {
    static FuckZombifiedPiglin instance;
    return instance;
}

bool FuckZombifiedPiglin::load() {
    getSelf().getLogger().info("Loading...");
    return true;
}

bool FuckZombifiedPiglin::enable() {
    getSelf().getLogger().info("Enabling...");
    return true;
}

bool FuckZombifiedPiglin::disable() {
    getSelf().getLogger().info("Disabling...");
    return true;
}

} // namespace fuckzombifiedpiglin


LL_REGISTER_MOD(fuckzombifiedpiglin::FuckZombifiedPiglin, fuckzombifiedpiglin::FuckZombifiedPiglin::getInstance());
