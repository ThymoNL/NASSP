/***************************************************************************
This file is part of Project Apollo - NASSP
Copyright 2019

IU Umbilical

Project Apollo is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

Project Apollo is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Project Apollo; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

See http://nassp.sourceforge.net/license/ for more details.

**************************************************************************/

#include "Orbitersdk.h"
#include "iu.h"
#include "IUUmbilicalInterface.h"
#include "IUUmbilical.h"

IUUmbilical::IUUmbilical(IUUmbilicalInterface *ml)
{
	IuUmb = ml;
	iu = NULL;
	IUUmbilicalConnected = false;
}

IUUmbilical::~IUUmbilical()
{
}

void IUUmbilical::Connect(IU *iu)
{
	if (iu)
	{
		this->iu = iu;
		iu->ConnectUmbilical(this);
		IUUmbilicalConnected = true;
	}
}

void IUUmbilical::Disconnect()
{
	if (!IUUmbilicalConnected) return;

	iu->DisconnectUmbilical();
	IUUmbilicalConnected = false;
}

void IUUmbilical::AbortDisconnect()
{
	IUUmbilicalConnected = false;
}

bool IUUmbilical::ESEGetCommandVehicleLiftoffIndicationInhibit()
{
	return IuUmb->ESEGetCommandVehicleLiftoffIndicationInhibit();
}

bool IUUmbilical::ESEGetSICOutboardEnginesCantInhibit()
{
	return IuUmb->ESEGetSICOutboardEnginesCantInhibit();
}

bool IUUmbilical::ESEGetSICOutboardEnginesCantSimulate()
{
	return IuUmb->ESEGetSICOutboardEnginesCantSimulate();
}

bool IUUmbilical::ESEGetAutoAbortInhibit()
{
	return IuUmb->ESEGetAutoAbortInhibit();
}

bool IUUmbilical::ESEGetGSEOverrateSimulate()
{
	return IuUmb->ESEGetGSEOverrateSimulate();
}

bool IUUmbilical::ESEGetEDSPowerInhibit()
{
	return IuUmb->ESEGetEDSPowerInhibit();
}

bool IUUmbilical::ESEPadAbortRequest()
{
	return IuUmb->ESEPadAbortRequest();
}

bool IUUmbilical::ESEGetThrustOKIndicateEnableInhibitA()
{
	return IuUmb->ESEGetThrustOKIndicateEnableInhibitA();
}

bool IUUmbilical::ESEGetThrustOKIndicateEnableInhibitB()
{
	return IuUmb->ESEGetThrustOKIndicateEnableInhibitB();
}

bool IUUmbilical::ESEEDSLiftoffInhibitA()
{
	return IuUmb->ESEEDSLiftoffInhibitA();
}

bool IUUmbilical::ESEEDSLiftoffInhibitB()
{
	return IuUmb->ESEEDSLiftoffInhibitB();
}

bool IUUmbilical::ESEAutoAbortSimulate()
{
	return IuUmb->ESEAutoAbortSimulate();
}

bool IUUmbilical::ESEGetSIBurnModeSubstitute()
{
	return IuUmb->ESEGetSIBurnModeSubstitute();
}

bool IUUmbilical::ESEGetGuidanceReferenceRelease()
{
	return IuUmb->ESEGetGuidanceReferenceRelease();
}

void IUUmbilical::SetEDSLiftoffEnableA()
{
	if (!IUUmbilicalConnected) return;

	iu->GetEDS()->SetEDSLiftoffEnableA();
}

void IUUmbilical::SetEDSLiftoffEnableB()
{
	if (!IUUmbilicalConnected) return;

	iu->GetEDS()->SetEDSLiftoffEnableB();
}

void IUUmbilical::EDSLiftoffEnableReset()
{
	if (!IUUmbilicalConnected) return;

	iu->GetEDS()->LiftoffEnableReset();
}

void IUUmbilical::SwitchFCCPowerOn()
{
	if (!IUUmbilicalConnected) return;

	iu->GetControlDistributor()->SetFCCPower(true);
}

void IUUmbilical::SwitchFCCPowerOff()
{
	if (!IUUmbilicalConnected) return;

	iu->GetControlDistributor()->SetFCCPower(false);
}

void IUUmbilical::SwitchQBallPowerOn()
{
	if (!IUUmbilicalConnected) return;

	iu->GetControlDistributor()->SetQBallPower(true);
}

void IUUmbilical::SwitchQBallPowerOff()
{
	if (!IUUmbilicalConnected) return;

	iu->GetControlDistributor()->SetQBallPower(false);
}

bool IUUmbilical::AllSIEnginesRunning()
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetEDS()->GetAllSIEnginesRunning();
}

bool IUUmbilical::IsEDSUnsafe()
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetEDS()->IsEDSUnsafe();
}

bool IUUmbilical::GetEDSSCCutoff1()
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetEDS()->GetLVEnginesCutoffFromSC1();
}

bool IUUmbilical::GetEDSSCCutoff2()
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetEDS()->GetLVEnginesCutoffFromSC2();
}

bool IUUmbilical::GetEDSSCCutoff3()
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetEDS()->GetLVEnginesCutoffFromSC3();
}

bool IUUmbilical::GetEDSAutoAbortBus()
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetEDS()->GetAutoAbort();
}

bool IUUmbilical::GetEDSExcessiveRateIndication()
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetEDS()->GetExcessiveRateIndication();
}

bool IUUmbilical::GetLVDCOutputRegisterDiscrete(int bit)
{
	if (!IUUmbilicalConnected) return false;

	return iu->GetLVDA()->GetOutputRegisterBit(bit);
}

void IUUmbilical::SetControlSignalProcessorPower(bool set)
{
	if (!IUUmbilicalConnected) return;

	iu->GetControlDistributor()->SetControlSignalProcessorPowerOn(set);
}

void IUUmbilical::SwitchSelector(int stage, int channel)
{
	iu->GetControlDistributor()->SwitchSelector(stage, channel);
}