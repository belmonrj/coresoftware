/*!
 * \file Jetv1.h
 * \brief Versionize the Jet object that make by Mike McCumber
 * \author Jin Huang <jhuang@bnl.gov>
 * \version $Revision:   $
 * \date $Date: $
 */

#ifndef G4JET_JETV1_H
#define G4JET_JETV1_H

#include "Jet.h"

#include <cstddef>  // for size_t
#include <iostream>
#include <limits>
#include <map>
#include <utility>  // for pair, make_pair

class PHObject;

/*!
 * \brief Jetv1
 */
class Jetv1 : public Jet
{
 public:
  Jetv1();
  ~Jetv1() override {}

  // PHObject virtual overloads

  void identify(std::ostream& os = std::cout) const override;
  void Reset() override;
  int isValid() const override;
  PHObject* CloneMe() const override;

  // jet info

  unsigned int get_id() const override { return _id; }
  void set_id(unsigned int id) override { _id = id; }

  float get_px() const override { return _mom[0]; }
  void set_px(float px) override { _mom[0] = px; }

  float get_py() const override { return _mom[1]; }
  void set_py(float py) override { _mom[1] = py; }

  float get_pz() const override { return _mom[2]; }
  void set_pz(float pz) override { _mom[2] = pz; }

  float get_e() const override { return _e; }
  void set_e(float e) override { _e = e; }

  float get_p() const override;
  float get_pt() const override;
  float get_et() const override;
  float get_eta() const override;
  float get_phi() const override;
  float get_mass() const override;
  float get_mass2() const override;

  // extended jet info

  bool has_property(Jet::PROPERTY prop_id) const override;
  float get_property(Jet::PROPERTY prop_id) const override;
  void set_property(Jet::PROPERTY prop_id, float value) override;
  void print_property(std::ostream& os) const override;

  //
  // clustered component methods (multimap interface based)
  // source type id --> unique id within that storage
  //
  bool empty_comp() const override { return _comp_ids.empty(); }
  size_t size_comp() const override { return _comp_ids.size(); }

  void clear_comp() override { _comp_ids.clear(); }
  size_t erase_comp(SRC source) override { return _comp_ids.erase(source); }
  void erase_comp(Iter iter) override
  {
    _comp_ids.erase(iter);
    return;
  }
  void erase_comp(Iter first, Iter last) override
  {
    _comp_ids.erase(first, last);
    return;
  }

  ConstIter begin_comp() const override { return _comp_ids.begin(); }
  ConstIter lower_bound_comp(SRC source) const override { return _comp_ids.lower_bound(source); }
  ConstIter upper_bound_comp(SRC source) const override { return _comp_ids.upper_bound(source); }
  ConstIter find(SRC source) const override { return _comp_ids.find(source); }
  ConstIter end_comp() const override { return _comp_ids.end(); }

  Iter begin_comp() override { return _comp_ids.begin(); }
  Iter lower_bound_comp(SRC source) override { return _comp_ids.lower_bound(source); }
  Iter upper_bound_comp(SRC source) override { return _comp_ids.upper_bound(source); }
  Iter find(SRC source) override { return _comp_ids.find(source); }
  Iter end_comp() override { return _comp_ids.end(); }

 private:
  /// unique identifier within container
  unsigned int _id = ~0x0;

  /// jet momentum vector (px,py,pz)
  float _mom[3]{};

  /// jet energy
  float _e {std::numeric_limits<float>::quiet_NaN()};

  /// source id -> component id
  typ_comp_ids _comp_ids;

  typedef std::map<Jet::PROPERTY, float> typ_property_map;
  /// map that contains extra properties
  typ_property_map _property_map;

  // Function in Jet.h header which are not implemented in Jet.h
  // messages for function calls from Jet.h which are not implemented in Jetv1.h
  static void not_in_v1_msg(const std::string& method_name, std::ostream& os = std::cout) ;
  size_t size_properties() const override { return _property_map.size(); };
  virtual std::vector<float>& get_property_vec() override;

  void insert_comp(SRC source, unsigned int compid) override
  {
    _comp_ids.insert(std::make_pair(source, compid));
  }
  void insert_comp(SRC source, unsigned int compid, bool) override;  // v2 only
  void insert_comp(TYPE_comp_vec&) override;                         // v2 only
  void insert_comp(TYPE_comp_vec&, bool) override;                   // v2 only
  void set_comp_sort_flag(bool) override;                            // let comp_vec know it isn't sorted
                                                                     //
  size_t num_comp(Jet::SRC /**/) override;
  void print_comp(std::ostream& /**/, bool /**/) override;
  std::vector<Jet::SRC> comp_src_vec() override;
  std::map<Jet::SRC, size_t> comp_src_sizemap() override;
  size_t count_comp(SRC source) const override { return _comp_ids.count(source); }

  ITER_comp_vec comp_begin(Jet::SRC /**/) override;
  ITER_comp_vec comp_end(Jet::SRC /**/) override;
  ITER_comp_vec comp_begin() override;
  ITER_comp_vec comp_end() override;
  TYPE_comp_vec& get_comp_vec() override;

  void resize_properties(size_t /**/) override;

  ClassDefOverride(Jetv1, 1);
};

#endif  // G4JET_JETV1_H
