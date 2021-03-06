/**************************************************************************

    Copyright (C) 2011  Eli Lilly and Company

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

**************************************************************************/
#ifndef PARSE_SMARTS_TMP_H
#define PARSE_SMARTS_TMP_H

/*
  When parsing a smarts, we need a lot of things passed around,
  so rather than having functions with way too many arguments
  we stick things into an object
*/

class Parse_Smarts_Tmp
{
  private:
    int _last_query_atom_created;

    resizable_array<Substructure_Atom *> _root;
    resizable_array<Bond *> _no_matched_atoms_between;
    resizable_array<Link_Atom *> _link_atom;

    extending_resizable_array<Substructure_Atom *> _completed;

  public:
    Parse_Smarts_Tmp ();
    ~Parse_Smarts_Tmp ();

    int set_natoms (int);

#ifdef PARSE_SMARTS_TMP_MALLOC_CHECK
    int check_malloc_magic () const;
#endif

    void add_root_atom (Substructure_Atom * r) { _root.add (r);}
    void add_no_matched_atoms_between (Bond * r) { _no_matched_atoms_between.add (r);}
    void add_link_atom (Link_Atom * r) { _link_atom.add (r);}

    extending_resizable_array<Substructure_Atom *> & completed () { return _completed;}

    void set_last_query_atom_created (int s) { _last_query_atom_created = s;}
    int last_query_atom_created () const { return _last_query_atom_created;}

    const resizable_array<Substructure_Atom *> & root_atoms () const { return _root;}
    const resizable_array<Bond *> & no_matched_atoms_between () const { return _no_matched_atoms_between;}
    const resizable_array<Link_Atom *> & link_atoms () const { return _link_atom;}
};

#endif
