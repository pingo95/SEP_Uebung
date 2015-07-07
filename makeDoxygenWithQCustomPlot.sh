echo "Generiere Doxygen-Dokumentation"
cd ./Code/Doxygen
doxygen doxygen-config-with-qcustomplot
cd ..
cd ..
ln -s ./Code/Doxygen/WithQCustomPlot/html/index.html starteDoxygenWithQCustomPlot.html
echo "Fertig. Zum Oeffnen der HTML-Dokumentation starteDoxygenWithQCustomPlot.html ausfuehren."
