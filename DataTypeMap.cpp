#include "DataTypeMap.h"


DataTypeMap::DataTypeMap()
{
	QStringList datatypes;
	//压力//
	datatypes << s_pressure<<s_voltagepressure<<s_Pi<<s_deltap<<s_dp<<s_matchdeltap
		<<s_matchdp<<s_semip<<s_matchsemip<<s_matchp<<s_Pcf<<s_Pcm<<s_ISIP<<s_GfunGdpdg<<s_Gfuncdpdg
		<<s_surfacepressure<<s_mergepressure;
	datatypesmap[s_pressure] = datatypes;
	datatypes.clear();
	//长度及深度//
	datatypes << s_rw << s_h<<s_Lfrac<<s_xf<<s_xfave<<s_xpos<<s_wf<<s_xposmin
		<<s_xposmax<<s_hres<<s_zw<<s_hfrac<<s_RN<<s_RS<<s_RE<<s_RW<<s_bgpos
		<<s_hdeep;
	datatypesmap[s_l] = datatypes;
	datatypes.clear();
	//时间
	datatypes << s_elapsetime << s_periodtime<<s_historystartt<<s_historyendt
		<<s_logstartt<<s_logendt<<s_deltat<<s_modifyt<<s_Gtp<<s_Gfunct
		<<s_ceprate<<s_twave<<s_testtime;
	datatypesmap[s_t] = datatypes;
	datatypes.clear();
	//产量
	datatypes << s_qpump<<s_qpumpave;
	datatypesmap[s_q] = datatypes;
	datatypes.clear();
	//加速度
	datatypes <<s_acclerationx<<s_acclerationy<<s_acclerationz<<s_vwave;
	datatypesmap[s_acc] = datatypes;
	datatypes.clear();
	//井筒储集系数
	datatypes << s_C;
	datatypesmap[s_C] = datatypes;
	datatypes.clear();
	//渗透率
	datatypes << s_Ksrv<<s_Kf;
	datatypesmap[s_K] = datatypes;
	datatypes.clear();
	//密度
	datatypes << s_density;
	datatypesmap[s_density] = datatypes;
	datatypes.clear();
	//柔度
	datatypes << s_Cfm << s_Cfn;
	datatypesmap[s_Cf] = datatypes;
	datatypes.clear();
	//体积
	datatypes << s_Vsrv << s_GVpump<<s_Vf;
	datatypesmap[s_V] = datatypes;
	datatypes.clear();
	//面积
	datatypes << s_Afm << s_Afn;
	datatypesmap[s_A] = datatypes;
	datatypes.clear();
}

DataTypeMap::~DataTypeMap()
{
}

QString DataTypeMap::getType(const QString&type)
{
	const QStringList types = datatypesmap.keys();
	if (types.contains(type)) {
		return type;
	}
	QString datatype;
	for (int i = 0; i < types.size(); i++) {
		if (datatypesmap[types[i]].contains(type)) {
			datatype = types[i];
			break;
		}
	}
	return datatype;
}
