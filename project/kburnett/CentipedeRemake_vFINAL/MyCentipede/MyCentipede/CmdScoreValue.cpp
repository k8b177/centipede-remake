// CmdScoreValue

#include "CmdScoreValue.h"

#include "ScoreManager.h"

#include "Game Components/TEAL/CommonElements.h" // required for ConsoleMsg but can get rid of later

CmdScoreValue::CmdScoreValue(int val, ScoreManager* pScoreManager)
	: points(val), pScoreManager(pScoreManager)
{
	ConsoleMsg::WriteLine("Score Command created: Points = %i\n" + std::to_string(val));
}

void CmdScoreValue::Execute()
{
	ConsoleMsg::WriteLine("\tScore Command Executing\n");
	pScoreManager->AddScore(points);
}

void CmdScoreValue::SendToManager()
{
	pScoreManager->SendScoreCmd(this);
}

void CmdScoreValue::SetSpiderPointer(Spider* s)
{
	// does nothing, value score commands don't have a spider pointer
}