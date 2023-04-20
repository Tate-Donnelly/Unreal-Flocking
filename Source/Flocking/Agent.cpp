#include "Kismet/KismetMathLibrary.h"
#include "Agent.h"

AAgent::AAgent() {
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AgentMesh"));
	RootComponent = Mesh;
	Velocity = FVector();
}

void AAgent::BeginPlay() {
	Super::BeginPlay();
}

void AAgent::Init(UStaticMeshComponent* mesh, int id) {
	UE_LOG(LogTemp, Warning, TEXT("Agent initialized."));
	Mesh->SetStaticMesh(mesh->GetStaticMesh());
}

void AAgent::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	FVector loc = GetActorLocation();
	SetActorLocation(loc + Velocity);

	FRotator rotation = UKismetMathLibrary::FindLookAtRotation(FVector(0.f), Velocity);
	SetActorRotation(rotation + FRotator(-90.f, 0.f, 0.f));
}