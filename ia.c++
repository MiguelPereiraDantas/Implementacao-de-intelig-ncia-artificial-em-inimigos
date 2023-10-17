#include "YourEnemyAIController.h"
#include "YourPlayerCharacter.h"

void AYourEnemyAIController::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

    AYourPlayerCharacter* PlayerCharacter = Cast<AYourPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));

    if (LineOfSightTo(PlayerCharacter, FVector(0, 0, 0), true))
    {
        MoveToActor(PlayerCharacter, AcceptanceRadius);

        // Implemente aqui a lógica de ataque ao alcançar o personagem do jogador
        // Por exemplo, você pode chamar uma função de ataque do inimigo quando estiver próximo o suficiente

        if (ShouldAttack(PlayerCharacter))
        {
            Attack();
        }
    }
}

bool AYourEnemyAIController::ShouldAttack(AYourPlayerCharacter* PlayerCharacter) const
{
    // Implemente aqui a lógica para decidir se o inimigo deve atacar
    // Por exemplo, você pode verificar a distância entre o inimigo e o personagem do jogador para tomar essa decisão

    FVector EnemyLocation = GetPawn()->GetActorLocation();
    FVector PlayerLocation = PlayerCharacter->GetActorLocation();
    float Distance = FVector::Dist(EnemyLocation, PlayerLocation);

    if (Distance < AttackRange)
    {
        return true;
    }
    return false;
}

void AYourEnemyAIController::Attack()
{
    // Implemente a lógica de ataque do inimigo aqui
    // Por exemplo, você pode chamar uma função de ataque do inimigo quando estiver próximo o suficiente
}
