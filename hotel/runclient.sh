#!/bin/bash

javac -classpath java-getopt-1.0.14.jar\:. HotelClient.java
java -cp ./*:. HotelClient -h
java -cp ./*:. HotelClient -b 1 Jan
java -cp ./*:. HotelClient localhost -g
