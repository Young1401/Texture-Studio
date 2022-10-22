/**********************************
 *                                *
 *     Creado por GROVE4L         *
 *   www.pawnoscripting.com       *
 *                                *
 **********************************/

#if defined _MaquinasGR_included
  #endinput
#endif
#define _MaquinasGR_included
#pragma library MaquinasGR

// native AgregarSprunk(Float:X,Float:Y,Float:Z,Float:rX,Float:rY,Float:rZ);

#define PRECIO		5 //Precio que cobraran las maquinitas
#define MAX_MACHINES	75 //Maximo de maquinas


enum Datos
{
	Float:PosSX,
	Float:PosSY,
	Float:PosSZ,
};
new MSprunks[MAX_MACHINES][Datos];
new SprunksTotales = 0;
new ObjetoSprunk[MAX_MACHINES];
new EnUso[MAX_PLAYERS];

QuiereBeber(playerid,newkeys)
{
	if(newkeys == KEY_SECONDARY_ATTACK && GetPlayerState(playerid) == PLAYER_STATE_ONFOOT)
	{
	    for(new M = 0; M < MAX_MACHINES; M++)
	    {
	        if(IsPlayerInRangeOfPoint(playerid,2,MSprunks[M][PosSX],MSprunks[M][PosSY],MSprunks[M][PosSZ]))
	        {
	            if(GetPlayerMoney(playerid) >= PRECIO && EnUso[playerid] == 0)
	            {
	                EnUso[playerid] = 1;
	                GivePlayerMoney(playerid,-PRECIO);
		            SetPlayerFacingObject(playerid, ObjetoSprunk[M]);
		            ApplyAnimation(playerid,"VENDING","VEND_Use",1.4,0, 1, 1, 0, 0);
		            SetTimerEx("FazerAnime",2000,0,"i",playerid);
		            SendClientMessage(playerid, 0x008B00AA, "| BEBIDA | Você gastou $5 na maquina de Refrigerante");
				}
				if(GetPlayerMoney(playerid) < PRECIO && EnUso[playerid] == 0)
				{
				SendClientMessage(playerid, 0xFF4500FF, "| ERRO | Você não tem dinheiro suficiente ( $5 )");
				}
			}
		}
	}
}

forward FazerAnime(playerid);
public FazerAnime(playerid)
{
	SetTimerEx("VidaYFin",950,0,"i",playerid);
	ApplyAnimation(playerid,"VENDING","VEND_Drink2_P",1.4,0, 1, 1, 0, 0);
	return 1;
}