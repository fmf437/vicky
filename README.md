## Vicky

#### Vicky is a converter of multimedia files, that converts video to sound files (.mp3) using ffmpeg and is currently at the version 1.6.0 .
#### Vicky is licensed under GNU GPL v.3 and is Copyright (C) 2014 2015 of Filipe Marques.
#### Build in C++11 Qt5. :smile:

If you use [Manjaro Linux](http://www.manjaro.org/) operating system, you can install vicky:

```
sudo pacman -S vicky
```

or in octopi or pamac search for: vicky

On the other hand, if you use [Archlinux](https://www.archlinux.org/) you can install vicky
using the [Arch User Repository](https://aur.archlinux.org) and yaourt:

```
yaourt -S vicky
```

#### What currently does:
- if you select one file and click convert that file will be converted;
- if you select one or more files at once that files will be converted;

#### Known bugs:
- the progress bar don't work as expected (this will be fixed in future versions);

#### Milestones:
- fixing the known (and unknown bugs - they might exist);
- adding a window of options to add more formats, to convert;

### Contributing to Vicky project

Here are the rules to promote a good relationship between developers and the community:

#### Issues

1. Be polite and kind
2. Describe what happens and how to test to reproduce that error

#### Pull requests

1. To fix a issue: one pull request per issue
2. To implement an idea: one pull request per idea

#### Development

1. Always develop new features, fix bugs in dev branch, after finish develop, merge dev into master branch of your forked repo.
2. Do pull requests to target the dev branch

This avoids confusion between revisions of source code!

#### Software need for coding or testing

* C++ tool chain: [g++](https://gcc.gnu.org/), [qt5, qtcreator, qmake](http://qt-project.org/), [make](http://www.gnu.org/software/make/)
* Good Knowledge of [C++11](http://isocpp.org/)
* [git](http://git-scm.com/)

#### Building

After clonning the project, open Qt Creator and then open the project Vicky and you are ready to develop !

#### Have a happy coding ! :thumbsup:
