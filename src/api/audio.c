#include "api/lovr.h"
#include "audio/audio.h"
#include "audio/source.h"
#include "loaders/source.h"

map_int_t TimeUnits;

int l_lovrAudioInit(lua_State* L) {
  lua_newtable(L);
  luaL_register(L, NULL, lovrAudio);
  luax_registertype(L, "Source", lovrSource);

  map_init(&TimeUnits);
  map_set(&TimeUnits, "seconds", UNIT_SECONDS);
  map_set(&TimeUnits, "samples", UNIT_SAMPLES);

  lovrAudioInit();
  return 1;
}

int l_lovrAudioUpdate(lua_State* L) {
  lovrAudioUpdate();
  return 0;
}

int l_lovrAudioGetOrientation(lua_State* L) {
  float angle, ax, ay, az;
  lovrAudioGetOrientation(&angle, &ax, &ay, &az);
  lua_pushnumber(L, angle);
  lua_pushnumber(L, ax);
  lua_pushnumber(L, ay);
  lua_pushnumber(L, az);
  return 4;
}

int l_lovrAudioGetPosition(lua_State* L) {
  float x, y, z;
  lovrAudioGetPosition(&x, &y, &z);
  lua_pushnumber(L, x);
  lua_pushnumber(L, y);
  lua_pushnumber(L, z);
  return 3;
}

int l_lovrAudioGetVelocity(lua_State* L) {
  float x, y, z;
  lovrAudioGetVelocity(&x, &y, &z);
  lua_pushnumber(L, x);
  lua_pushnumber(L, y);
  lua_pushnumber(L, z);
  return 3;
}

int l_lovrAudioGetVolume(lua_State* L) {
  lua_pushnumber(L, lovrAudioGetVolume());
  return 1;
}

int l_lovrAudioIsSpatialized(lua_State* L) {
  lua_pushboolean(L, lovrAudioIsSpatialized());
  return 1;
}

int l_lovrAudioNewSource(lua_State* L) {
  Blob* blob = luax_readblob(L, 1, "Source");
  SourceData* sourceData = lovrSourceDataCreate(blob);
  Source* source = lovrSourceCreate(sourceData);
  luax_pushtype(L, Source, source);
  lovrRelease(&source->ref);
  lovrRelease(&blob->ref);
  return 1;
}

int l_lovrAudioPause(lua_State* L) {
  lovrAudioPause();
  return 0;
}

int l_lovrAudioResume(lua_State* L) {
  lovrAudioResume();
  return 0;
}

int l_lovrAudioRewind(lua_State* L) {
  lovrAudioRewind();
  return 0;
}

int l_lovrAudioSetOrientation(lua_State* L) {
  float angle = luaL_checknumber(L, 1);
  float ax = luaL_checknumber(L, 2);
  float ay = luaL_checknumber(L, 3);
  float az = luaL_checknumber(L, 4);
  lovrAudioSetOrientation(angle, ax, ay, az);
  return 0;
}

int l_lovrAudioSetPosition(lua_State* L) {
  float x = luaL_checknumber(L, 1);
  float y = luaL_checknumber(L, 2);
  float z = luaL_checknumber(L, 3);
  lovrAudioSetPosition(x, y, z);
  return 0;
}

int l_lovrAudioSetVelocity(lua_State* L) {
  float x = luaL_checknumber(L, 1);
  float y = luaL_checknumber(L, 2);
  float z = luaL_checknumber(L, 3);
  lovrAudioSetVelocity(x, y, z);
  return 0;
}

int l_lovrAudioSetVolume(lua_State* L) {
  float volume = luaL_checknumber(L, 1);
  lovrAudioSetVolume(volume);
  return 0;
}

int l_lovrAudioStop(lua_State* L) {
  lovrAudioStop();
  return 0;
}

const luaL_Reg lovrAudio[] = {
  { "update", l_lovrAudioUpdate },
  { "getOrientation", l_lovrAudioGetOrientation },
  { "getPosition", l_lovrAudioGetPosition },
  { "getVelocity", l_lovrAudioGetVelocity },
  { "getVolume", l_lovrAudioGetVolume },
  { "isSpatialized", l_lovrAudioIsSpatialized },
  { "newSource", l_lovrAudioNewSource },
  { "pause", l_lovrAudioPause },
  { "resume", l_lovrAudioResume },
  { "rewind", l_lovrAudioRewind },
  { "setOrientation", l_lovrAudioSetOrientation },
  { "setPosition", l_lovrAudioSetPosition },
  { "setVelocity", l_lovrAudioSetVelocity },
  { "setVolume", l_lovrAudioSetVolume },
  { "stop", l_lovrAudioStop },
  { NULL, NULL }
};
