#include "UnitChange.h"
#include"ConstUnit.h"
#include"ConstBasic.h"
#include"DataTypeMap.h"

UnitChange::UnitChange()
{
	DataMap unitsandCon;
	unitsandCon[s_kgm3] = 1;
	unitchangemap[s_sandCon] = unitsandCon;
	standardunitmap[s_sandCon] = s_kgm3;


	DataMap unitlength;
	unitlength[s_m] = 1;
	unitlength[s_cm] = 100;
	unitlength[s_km] = 0.001;
	unitlength[s_mm] = 1000;
	unitchangemap[s_l] = unitlength;
	standardunitmap[s_l] = s_m;
	standardunitmap[s_wf] = s_mm;


	DataMap unitacc;
	unitacc[s_mis] = 1;
	unitchangemap[s_acc] = unitacc;
	standardunitmap[s_acc] = s_mis;
	standardunitmap[s_vwave] = s_mis;

	DataMap unitcompress;
	unitcompress[s_rMPa] = 1;
	unitcompress[s_rKPa] = 0.0000001;
	unitcompress[s_rPa] = 0.001;
	unitcompress[s_ratm] = 0.101419;
	unitcompress[s_rpsia] = 0.0068;
	unitchangemap[s_compress] = unitcompress;

	standardunitmap[s_compress] = s_rMPa;

	DataMap unitpress;
	unitpress[s_MPa] = 1;
	unitpress[s_Pa] = 1000000;
	unitpress[s_KPa] = 1000;
	unitpress[s_atm] = 9.86923;
	unitpress[s_psia] = 145.0326;
	unitchangemap[s_pressure] = unitpress;

	standardunitmap[s_pressure] = s_MPa;

	DataMap unittime;
	unittime[s_hr] = 1.0;
	unittime[s_sec] = 3600;
	unittime[s_min] = 60;
	unittime[s_day] = 0.041666;
	unittime[s_week] = 0.00596;
	unittime[s_ms] = 3600000;
	unitchangemap[s_t] = unittime;
	standardunitmap[s_t] = s_hr;
	standardunitmap[s_wht] = s_sec;
	standardunitmap[s_ceprate] = s_sec;
	standardunitmap[s_twave] = s_sec;

	DataMap unitrate;
	unitrate[s_m3d] = 1440;
	unitrate[s_m3min] =1;
	unitrate[s_m3hr] = 60;
	
	unitchangemap[s_q] = unitrate;
	standardunitmap[s_q] = s_m3min;

	DataMap volumnfactormap;
	volumnfactormap[s_m3stm3] = 1;
	volumnfactormap[s_bstb] = 1;
	volumnfactormap[s_cfstb] = 5.61458;
	unitchangemap[s_B] = volumnfactormap;

	standardunitmap[s_B] = s_m3stm3;

	DataMap viscositymap;
	viscositymap[s_cp] = 1;
	viscositymap[s_upasec] = 1000;
	viscositymap[s_pasec] = 0.001;
	unitchangemap[s_u] = viscositymap;
	standardunitmap[s_u] = s_cp;

	DataMap tempraturemap;
	tempraturemap[s_dC] = 1;
	tempraturemap[s_TK] = 1;
	unitchangemap[s_temprature] = tempraturemap;
	standardunitmap[s_temprature] = s_dC;

	DataMap datemap;
	datemap[s_yyyyMMdd] = 1;
	unitchangemap[s_date] = datemap;
	standardunitmap[s_date] = s_yyyyMMdd;

	DataMap timemap;
	timemap[s_hhmmss] = 1;
	timemap[s_hmmss] = 1;
	unitchangemap[s_time] = timemap;
	standardunitmap[s_time] = s_hhmmss;

	DataMap datetimemap;
	datetimemap[s_datetimeformat] = 1;
	datetimemap[s_datetimeformat2] = 1;
	unitchangemap[s_datetime] = datetimemap;
	QString standarddatetimeunit;
	standarddatetimeunit = s_yyyyMMdd + s_linefeed + s_hhmmss;
	standardunitmap[s_datetime] = standarddatetimeunit;
	
	DataMap unitwellstorage;
	unitwellstorage[s_m3_Mpa] = 1;
	unitwellstorage[s_m3_Kpa] = 1000;
	unitchangemap[s_C] = unitwellstorage;
	standardunitmap[s_C] = s_m3_Mpa;

	DataMap unitperm;
	unitperm[s_mD] = 1;
	unitperm[s_D] = 0.001;
	unitchangemap[s_K] = unitperm;
	standardunitmap[s_K] = s_mD;

	DataMap unitfc;
	unitfc[s_mDm] = 1;
	unitfc[s_Dm] = 1000;
	unitchangemap[s_fcave] = unitfc;
	standardunitmap[s_fcave] = s_mDm;
	unitchangemap[s_kh] = unitfc;
	standardunitmap[s_kh] = s_mDm;

	DataMap unitdensity;
	unitdensity[s_kgm3] = 1000;
	unitdensity[s_gcm3] = 1;
	unitchangemap[s_density] = unitdensity;
	standardunitmap[s_density] = s_gcm3;

	DataMap unitvolumn;
	unitvolumn[s_m3] = 1;
	unitchangemap[s_V] = unitvolumn;
	standardunitmap[s_V] = s_m3;

	DataMap unitarea;
	unitarea[s_m2] = 1;
	unitchangemap[s_A] = unitarea;
	standardunitmap[s_A] = s_m2;

	DataMap unitkhu;
	unitkhu[s_mDm_cp] = 1;
	unitchangemap[s_khu] = unitkhu;
	standardunitmap[s_khu] = s_mDm_cp;

	DataMap unitflex;
	unitflex[s_m_MPa] = 1;
	unitchangemap[s_Cf] = unitflex;
	standardunitmap[s_Cf] = s_m_MPa;
}

UnitChange::~UnitChange()
{
}

void UnitChange::changeUnitValue(const QString& previousunit, const QString& currentunit, const QString& type, double& value)
{
	DataTypeMap* datatypemap = SingleTemplate<DataTypeMap>::getInstance();
	const QString datatype = datatypemap->getType(type);
	if (!datatype.isEmpty()) {
		if (datatype == s_temprature) {
			changeTempratureUnit(previousunit, currentunit, value);
		}
		else {
			double factor = getChangeFactor(previousunit, currentunit, datatype);
			value *= factor;
		}
	}
}

void UnitChange::changeUnitVector(const QString& previousunit, const QString& currentunit, const QString& type, QVector<double>& data)
{
	double factor = getChangeFactor(previousunit, currentunit, type);
	for (int i = 0; i < data.size(); i++) {
		data[i] *= factor;
	}
}

void UnitChange::checkStandardVector(const QString& type, const QString& unittype, QVector<double>& data)
{
	QString standardunit = getStandardUnit(type);
	if (unittype != standardunit) {
		changeUnitVector(unittype, standardunit, type, data);
	}
}

void UnitChange::checkTableVector(const QString& type, const QString& unittype, QVector<double>& data)
{
	QString standardunit = getStandardUnit(type);
	if (unittype != standardunit) {
		changeUnitVector(standardunit, unittype, type, data);
	}
}

void UnitChange::checkStandardValue(const QString& type, const QString& unit, double& value)
{
	QString standardunit = getStandardUnit(type);
	if (unit != standardunit) {
		changeUnitValue(unit, standardunit, type, value);
	}
}

void UnitChange::checkTableValue(const QString& type, const QString& unit, double& value)
{
	QString standardunit = getStandardUnit(type);
	if (unit != standardunit) {
		changeUnitValue(standardunit, unit, type, value);
	}
}

void UnitChange::changeTempratureUnit(const QString& previousunit, const QString& currentunit, double& value)
{
	const double factor = 273.15;
	if (previousunit == s_TK) {
		value -= 273.15;
	}
	else {
		value += 273.15;
	}
}


double UnitChange::getChangeFactor(const QString& previousunit, const QString& currentunit, const QString& type)
{
	QString datatype = type;
	if (!unitchangemap.contains(type)) {
		DataTypeMap* datatypemap = SingleTemplate<DataTypeMap>::getInstance();
		datatype = datatypemap->getType(type);
	}

	const double previousvalue = unitchangemap[datatype][previousunit];
	const double currentvalue = unitchangemap[datatype][currentunit];
	return currentvalue / previousvalue;
}

double UnitChange::getChangeFactor(const QString& type, const QString& unit)
{
	DataTypeMap* datatypemap = SingleTemplate<DataTypeMap>::getInstance();
	QString datatype = datatypemap->getType(type);
	QString standardunit;
	if (!standardunitmap.contains(type)) {
		standardunit = getStandardUnit(datatype);
	}
	else {
		standardunit = getStandardUnit(type);
	}

	const double previousvalue = unitchangemap[datatype][standardunit];
	const double currentvalue = unitchangemap[datatype][unit];
	return currentvalue / previousvalue;
}

QString UnitChange::getStandardUnit(const QString& type)
{
	QString standardunit;
	if (standardunitmap.contains(type)) {
		standardunit = standardunitmap[type];
	}
	else {
		DataTypeMap* datatypemap = SingleTemplate<DataTypeMap>::getInstance();
		QString unittype = datatypemap->getType(type);
		standardunit = standardunitmap[unittype];
	}
	return standardunit;
}

QStringList UnitChange::getUnits(const QString& type)
{
	QStringList units;

	if (unitchangemap.contains(type)) {
		units = unitchangemap[type].keys();
	}
	else {
		DataTypeMap* datatypemap = SingleTemplate<DataTypeMap>::getInstance();
		QString unittype = datatypemap->getType(type);
		if (!unittype.isEmpty()) {
			units = unitchangemap[unittype].keys();
		}
	}
	return units;
}

StringDataMap UnitChange::getUnitChangeMap() const
{
	return unitchangemap;
}

QString UnitChange::getPlotAxisLabel(const QString&type)
{
	QString axislabel;
	axislabel = type;
	QString standardunit = getStandardUnit(type);
	if (!standardunit.isEmpty()) {
		axislabel += s_interval;
		axislabel += standardunit;
	}
	return axislabel;
}

void UnitChange::changeStandardunitToCurrentUnit(const QString&type, const QString&unit, double&value)
{
	QString standardunit = getStandardUnit(type);
	if (unit != standardunit) {
		changeUnitValue(standardunit,unit,type,value);
	}
	
}

QStringList UnitChange::getUnitParaTypes()const
{
	QStringList types = unitchangemap.keys();
	types.removeOne(s_time);
	types.removeOne(s_date);
	return types;
}

