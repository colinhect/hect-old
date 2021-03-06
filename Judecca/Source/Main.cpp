#include <Hect.h>

using namespace hect;

#ifdef HECT_WINDOWS
#ifdef HECT_DEBUG
#include <vld.h>
#endif
#endif

#include "States/GalaxyViewerState.h"

int main()
{
    try
    {
        Engine engine("Solid Black", "Settings.json");

        engine.pushState<GalaxyViewerState>(engine);
        engine.execute();
    }
    catch (std::exception& e)
    {
        Engine::fatalError(e.what());
    }

    return 0;
}