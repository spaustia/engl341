//
// Override the StudioModelRender virtual member functions here to implement custom bone
// setup, blending, etc.
//

// Global engine <-> studio model rendering code interface
extern engine_studio_api_t IEngineStudio;

// The renderer object, created on the stack.
CGameStudioModelRenderer g_StudioRenderer;
/*
====================
CGameStudioModelRenderer
====================
*/
CGameStudioModelRenderer::CGameStudioModelRenderer( void )
{
}

////////////////////////////////////
// Hooks to class implementation
////////////////////////////////////

/*
====================
HUD_GetStudioModelInterface
Export this function for the engine to use the studio renderer class to render objects.
====================
*/
int CL_DLLEXPORT HUD_GetStudioModelInterface( int version, struct r_studio_interface_s **ppinterface, struct engine_studio_api_s *pstudio )
{
//  RecClStudioInterface(version, ppinterface, pstudio);

  if ( version != STUDIO_INTERFACE_VERSION )
    return 0;

  // Point the engine to our callbacks
  *ppinterface = &studio;

  // Copy in engine helper functions
  memcpy( &IEngineStudio, pstudio, sizeof( IEngineStudio ) );

  // Initialize local variables, etc.
  R_StudioInit();

  // Success
  return 1;
}