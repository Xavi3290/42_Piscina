#!/bin/bash

# Ejecuta el comando git log para mostrar los IDs de los últimos 5 commits
git log -n5 --format="%H" 
