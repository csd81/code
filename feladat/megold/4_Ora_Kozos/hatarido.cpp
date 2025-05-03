#include "hatarido.h"
#include <iostream>

Datum Hatarido::aktualisDatum(2023,2,27); // A mai nap

Hatarido::Hatarido(const string &n):
	nev(n)
{
}

Hatarido::~Hatarido()
{
	if (alphaDatum) delete alphaDatum;
	if (betaDatum) delete betaDatum;
	if (vegsoDatum) delete vegsoDatum;
}

Hatarido::Hatarido(const Hatarido &h):
	nev(h.nev)
{
	if (h.alphaDatum) alphaDatum=new Datum(*h.alphaDatum);
	else alphaDatum=nullptr;
	if (h.betaDatum) betaDatum=new Datum(*h.betaDatum);
	else betaDatum=nullptr;
	if (h.vegsoDatum) vegsoDatum=new Datum(*h.vegsoDatum);
	else vegsoDatum=nullptr;
}

string Hatarido::getNev() const
{
	return nev;
}

void Hatarido::setNev(const string &_nev)
{
	nev = _nev;
}

const Datum *Hatarido::getAlphaDatum() const
{
	return alphaDatum;
}

void Hatarido::setAlphaDatum(const Datum &_alpha)
{
	// Egyik megoldás: kitörölni és újrafoglalni
//	if (alpha) delete alpha;
//	alpha=new Datum(_alpha);

	// Másik megoldás: nem törlünk, és csak akkor foglalunk ha még nincs, egyébként másolunk
	if (alphaDatum==nullptr) alphaDatum=new Datum(_alpha);
	else *alphaDatum=_alpha;
}

const Datum *Hatarido::getBetaDatum() const
{
	return betaDatum;
}

void Hatarido::setBetaDatum(const Datum &_beta)
{
	if (betaDatum==nullptr) betaDatum=new Datum(_beta);
	else *betaDatum=_beta;
}

const Datum *Hatarido::getVegsoDatum() const
{
	return vegsoDatum;
}

void Hatarido::setVegsoDatum(const Datum &_vegso)
{
	if (vegsoDatum==nullptr) vegsoDatum=new Datum(_vegso);
	else *vegsoDatum=_vegso;
}

void Hatarido::hataridoTorol(const string &melyik)
{
	if (melyik=="alpha" && alphaDatum)
	{
		delete alphaDatum;
		alphaDatum=nullptr;
	}
	else if (melyik=="beta" && betaDatum)
	{
		delete betaDatum;
		betaDatum=nullptr;
	}
	else if (melyik=="vegso" && vegsoDatum)
	{
		delete vegsoDatum;
		vegsoDatum=nullptr;
	}
}

const Datum &Hatarido::getAktualisDatum()
{
	return aktualisDatum;
}

void Hatarido::setAktualisDatum(const Datum &newAktualisDatum)
{
	aktualisDatum = newAktualisDatum;
}

void Hatarido::lejart() const
{
	if (alphaDatum && alphaDatum->kisebbMint(aktualisDatum)) cout << "Az alpha hatarido lejart" << endl;
	if (betaDatum && betaDatum->kisebbMint(aktualisDatum)) cout << "A beta hatarido lejart" << endl;
	if (vegsoDatum && vegsoDatum->kisebbMint(aktualisDatum)) cout << "A vegso hatarido lejart" << endl;
}
