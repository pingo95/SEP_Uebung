echo "Generiere Doxygen-Dokumentation"
cd ./Code/Doxygen
doxygen doxygen-config-without-qcustomplot
cd ..
cd ..
ln -s ./Code/Doxygen/WithoutQCustomPlot/html/index.html starteDoxygen.html
echo "Fertig. Zum Oeffnen der HTML-Dokumentation starteDoxygen.html ausfuehren."
