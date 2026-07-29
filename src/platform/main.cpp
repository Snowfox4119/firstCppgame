#include <raylibSafe.h>
#include <iostream>

#include <imgui.h>
#include <rlImGui.h>

#include <gameMain.h>

void ApplySakuraTheme() {
    ImGuiStyle& style = ImGui::GetStyle();
    ImVec4* colors = style.Colors;

    // Base background colors (dark plum / soft charcoal)
    colors[ImGuiCol_WindowBg]         = ImVec4(0.12f, 0.10f, 0.13f, 0.95f);
    colors[ImGuiCol_ChildBg]          = ImVec4(0.15f, 0.12f, 0.16f, 1.00f);
    colors[ImGuiCol_PopupBg]          = ImVec4(0.12f, 0.10f, 0.13f, 0.94f);

    // Text colors
    colors[ImGuiCol_Text]             = ImVec4(0.95f, 0.88f, 0.92f, 1.00f);
    //colors[ImVec4(0.53f, 0.53f, 0.53f, 1.00f)] = ImVec4(0.60f, 0.50f, 0.57f, 1.00f); // TextDisabled

    // Headers & Selection (Soft Blossom Pink)
    colors[ImGuiCol_Header]           = ImVec4(0.78f, 0.47f, 0.63f, 0.45f);
    colors[ImGuiCol_HeaderHovered]    = ImVec4(0.88f, 0.56f, 0.73f, 0.80f);
    colors[ImGuiCol_HeaderActive]     = ImVec4(0.92f, 0.45f, 0.68f, 1.00f);

    // Buttons (Blossom Rose to De#include <iostream>ep Pink)
    colors[ImGuiCol_Button]           = ImVec4(0.76f, 0.42f, 0.60f, 0.60f);
    colors[ImGuiCol_ButtonHovered]    = ImVec4(0.87f, 0.51f, 0.70f, 1.00f);
    colors[ImGuiCol_ButtonActive]     = ImVec4(0.92f, 0.38f, 0.65f, 1.00f);

    // Frame Backgrounds (Inputs, Sliders)
    colors[ImGuiCol_FrameBg]          = ImVec4(0.22f, 0.17f, 0.24f, 0.54f);
    colors[ImGuiCol_FrameBgHovered]   = ImVec4(0.35f, 0.24f, 0.38f, 0.54f);
    colors[ImGuiCol_FrameBgActive]    = ImVec4(0.48f, 0.31f, 0.52f, 0.67f);

    // Tabs
    colors[ImGuiCol_Tab]              = ImVec4(0.68f, 0.39f, 0.54f, 0.86f);
    colors[ImGuiCol_TabHovered]       = ImVec4(0.88f, 0.51f, 0.70f, 0.80f);
    colors[ImGuiCol_TabActive]        = ImVec4(0.92f, 0.45f, 0.68f, 1.00f);

    // Borders & Misc Highlights
    colors[ImGuiCol_Border]           = ImVec4(0.55f, 0.35f, 0.48f, 0.50f);
    colors[ImGuiCol_CheckMark]        = ImVec4(0.98f, 0.65f, 0.82f, 1.00f);
    colors[ImGuiCol_SliderGrab]       = ImVec4(0.92f, 0.55f, 0.74f, 1.00f);
    colors[ImGuiCol_SliderGrabActive] = ImVec4(0.98f, 0.65f, 0.82f, 1.00f);

    // Rounding adjustments for a softer/cozy UI look
    style.WindowRounding = 6.0f;
    style.FrameRounding  = 4.0f;
    style.PopupRounding  = 4.0f;
    style.GrabRounding   = 3.0f;
}

int main()
{   
#if PRODUCTION_BUILD == 1
    SetTraceLogLevel(LOG_NONE); // No log output to the console by raylib.
#endif

	SetConfigFlags(FLAG_WINDOW_RESIZABLE);
	InitWindow(800,450, "window name");
    SetExitKey(KEY_NULL); // Diable Esc from closing the window.
    SetTargetFPS(240);

#pragma region imgui
	rlImGuiSetup(true);
	ApplySakuraTheme();

	ImGuiIO &io = ImGui::GetIO();
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; //Enable Keyboard Controls
	////io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad; // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable; //Enable Docking
	io.FontGlobalScale = 2;

#pragma endregion

    if(!initGame())
    { return 0; }

	while(!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(BLACK);

	#pragma region imgui
		rlImGuiBegin();
		
		//Docking stuff...
		ImGui::PushStyleColor(ImGuiCol_WindowBg, {});
		ImGui::PushStyleColor(ImGuiCol_DockingEmptyBg, {});
		ImGui::DockSpaceOverViewport(ImGui::GetMainViewport());
		ImGui::PopStyleColor(2);

	#pragma endregion

        if(!updateGame()){
            CloseWindow();
        }

		rlImGuiEnd();

		EndDrawing();
	}
#pragma region imgui
	rlImGuiShutdown();

#pragma endregion

	CloseWindow();
    closeGame();
    rlImGuiShutdown();

	return 0;
}
