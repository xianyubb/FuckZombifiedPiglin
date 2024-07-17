#include "plugin/FuckZombifiedPiglin.h"

#include <memory>

#include "ll/api/memory/Hook.h"
#include "ll/api/plugin/NativePlugin.h"
#include "ll/api/plugin/RegisterHelper.h"
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
    // Code for loading the plugin goes here.
    return true;
}

bool FuckZombifiedPiglin::enable() {
    getSelf().getLogger().info("Enabling...");
    // Code for enabling the plugin goes here.
    return true;
}

bool FuckZombifiedPiglin::disable() {
    getSelf().getLogger().info("Disabling...");
    // Code for disabling the plugin goes here.
    return true;
}

} // namespace fuckzombifiedpiglin

LL_REGISTER_PLUGIN(fuckzombifiedpiglin::FuckZombifiedPiglin, fuckzombifiedpiglin::instance);
