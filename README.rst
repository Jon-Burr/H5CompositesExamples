======================
H5 Composites Examples
======================

These examples are intended to demonstrate how to use the H5Composites package

.. contents:: Contents

Particles
---------

This example demonstrates how to create basic H5 tables (designed to be read e.g. by pandas) using the library.
Each row of the output table is constructed in C++ structs, here called ``EventData`` and ``ParticleData``.

.. include:: include/H5CompositesExamples/ParticleData.h
    :code: cpp