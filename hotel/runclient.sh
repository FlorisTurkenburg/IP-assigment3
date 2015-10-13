#!/bin/bash

javac -classpath java-getopt-1.0.14.jar\:. HotelClient.java

java -cp ./*:. HotelClient localhost -h
java -cp ./*:. HotelClient localhost -b 1 Jan
java -cp ./*:. HotelClient localhost -g
