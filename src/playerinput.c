#include "libtetris.h"

bool PlayerInputFormation(Formation *formation) {
  if (IsKeyReleased(KEY_LEFT)) {
    return FormationMove(formation, TRANSITION_LEFT);
  } else if (IsKeyReleased(KEY_RIGHT)) {
    return FormationMove(formation, TRANSITION_RIGHT);
  } else if (IsKeyDown(KEY_DOWN)) {
    return FormationMove(formation, TRANSITION_DOWN);
  } else if (IsKeyReleased(KEY_UP)) {
    FormationRotateLeft(formation);
  }
  return true;
}

void PlayerInputGame(Game *game) {
  if (IsKeyReleased(KEY_P)) {
    GameTogglePaused(game);
  } else if (IsKeyReleased(KEY_R)) {
    GameSetState(game, GameInitializing);
  } else if (IsKeyReleased(KEY_Q)) {
    GameSetState(game, GameTerminate);
  }
}
