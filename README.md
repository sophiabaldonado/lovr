<p align="center"><a href="http://lovr.org"><img src="src/data/logo.png" width="160"></a></p>

<h1 align="center">LÖVR</h1>

LÖVR is a simple framework for creating virtual reality experiences with Lua.

[![Build status](https://ci.appveyor.com/api/projects/status/alx3kdi35bmxka8c/branch/master?svg=true)](https://ci.appveyor.com/project/bjornbytes/lovr/branch/master)

Features
---

- Automatically detects and renders to connected VR headsets (works without a headset too!)
- Simple 3D graphics API supporting primitives, 3D models, fonts, shaders, skyboxes, framebuffers, etc.
- Create projects for Windows, macOS, Linux, or WebVR
- Spatialized audio
- 3D physics

Screenshots
---

<p align="center">
  <span><img src="http://lovr.org/static/img/wattle.jpg" width="32%"/></span>
  <span><img src="http://lovr.org/static/img/levrage.jpg" width="32%"/></span>
  <span><img src="http://lovr.org/static/img/planets.jpg" width="32%"/></span>
</p>

Getting Started
---

You can download precompiled binaries from the [website](http://lovr.org).  There, you
can also find documentation and a set of tutorials and examples.  Here is the hello world example
for LÖVR:

```lua
function lovr.draw()
  lovr.graphics.print('Hello World!', 0, 1.7, -3, .5)
end
```

To run it, first create a folder for your project and put the code in a file called `main.lua`.
Then, just drop the `project` folder onto `lovr.exe` (or run `lovr.exe path/to/project` on the
command line).  Put on your headset and you should see the text at the front of your play area!

#### Spinning Cube

```lua
function lovr.draw()
  lovr.graphics.cube('line', 0, 1, 0, .5, lovr.timer.getTime())
end
```

#### 3D Models

```lua
function lovr.load()
  model = lovr.graphics.newModel('teapot.fbx', 'teapot.png')
end

function lovr.draw()
  model:draw()
end
```

#### Audio

```lua
function lovr.load()
  local sound = lovr.audio.newSource('darudeSandstorm.ogg')
  sound:play()
end
```

Documentation
---

Documentation and examples are available on the website [here](http://lovr.org/docs).  The website is also [open source](https://github.com/bjornbytes/lovr-docs) if you want to add or edit documentation.

Community
---

> If you wanna be my LÖVR, you gotta get with my friends
> *- Spice Girls*

Feel free to join the [LÖVR Slack](https://join.slack.com/ifyouwannabemylovr/shared_invite/MTc5ODk2MjE0NDM3LTE0OTQxMTIyMDEtMzdhOGVlODFhYg) for questions, info, and other discussion.

Compiling
---

To compile from source to create a custom build or contribute to LÖVR, see
[`COMPILING`](COMPILING.md).

Contributing
---

Contributions are welcome!  See [`CONTRIBUTING`](CONTRIBUTING.md) for more information.

License
---

MIT, see [`LICENSE`](LICENSE) for details.
