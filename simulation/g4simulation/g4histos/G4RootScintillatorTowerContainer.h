#ifndef G4HISTOS_G4ROOTSCINTILLATORTOWERCONTAINER_H
#define G4HISTOS_G4ROOTSCINTILLATORTOWERCONTAINER_H

#include <phool/PHObject.h>

#include <iostream>  // for cout, ostream
#include <limits>

class G4RootScintillatorTower;
class TowerInfo;
class TClonesArray;

class G4RootScintillatorTowerContainer : public PHObject
{
 public:
  G4RootScintillatorTowerContainer();
  ~G4RootScintillatorTowerContainer() override;

  void Reset() override;
  void identify(std::ostream& os = std::cout) const override;

  G4RootScintillatorTower* AddTower(double towerenergy, int ieta, int iphi);

  void set_idet(const int i) { idet = i; }
  int get_idet() const { return idet; }

  void set_etotal(const float e) { etotal = e; }
  float get_etotal() const { return etotal; }

  void set_eion(const float e) { eion = e; }
  float get_eion() const { return eion; }

  void set_leakage(const float f) { leakage = f; }
  float get_leakage() const { return leakage; }

  void set_event(const int i) { event = i; }
  int get_event() const { return event; }

 protected:
  int idet{std::numeric_limits<int>::min()};
  float etotal{std::numeric_limits<float>::quiet_NaN()};
  float eion{std::numeric_limits<float>::quiet_NaN()};
  float leakage{std::numeric_limits<float>::quiet_NaN()};
  int event{0};
  TClonesArray* SnglTowers{nullptr};

  ClassDefOverride(G4RootScintillatorTowerContainer, 1)
};

#endif
