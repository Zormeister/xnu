# Zorm's XNU branching

## System

Branches are created from their major version, and then by the purpose of the branch:

Take the branch ``6153/dev``, ``6153`` is the major version of XNU that is being used, ``dev`` refers to the development nature of it.

This applies to the other available branches, ``6153/x86-dev``, for x86-64 development and ``6153/arm-dev`` for ARM/ARM64 development.

Usually, a ``<major>/dev`` branch should be the centralised development branch, having been merged into from the other available development branches.

For example, ``6153/dev`` has merges from ``6153/x86-dev`` and ``6153/arm-dev``.

## Active Branches

| Branches         | Description                              |
| ---------------- | ---------------------------------------- |
| ``6153/dev``     | Merged Darwin 19 development             |
| ``6153/arm-dev`` | ARM & ARM64 Darwin 19 development        |
| ``6153/x86-dev`` | Intel & AMD x86-64 Darwin 19 development |
