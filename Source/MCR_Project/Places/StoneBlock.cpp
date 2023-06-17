
#include "StoneBlock.h"
#include "../Tools/PickaxeTool.h"

bool AStoneBlock::bCouldMine(const ATool& Tool) const
{
	const APickaxeTool* Pick = Cast<const APickaxeTool>(&Tool);
	if(Pick)
	UE_LOG(LogTemp, Warning, TEXT("Pick found, getML %d >= requiredML %d"), Pick->GetMiningLevel(), RequiredMiningLevel);
	if (Pick && Pick->GetMiningLevel() >= RequiredMiningLevel)
	{
		return true;
	}

	return false;
}

