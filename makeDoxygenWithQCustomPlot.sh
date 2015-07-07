echo "Generiere Doxygen Dokumenation"
cd ./Code/Doxygen
doxygen doxygen-config-with-qcustomplot
cd ..
cd ..
ln -s Code/Doxygen/WithQCustomPlot/html/index.html starteDoxygenWithQCustomPlot
echo "Fertig. Zum Oeffnen der html-Doxygendokumentation mit QCustomPlot starteDoxygenWithQCustomPlot ausfuehren."
