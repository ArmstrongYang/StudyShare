/* ----------------------------------------------------- */
/* FUNCTIONS */
/* ----------------------------------------------------- */
function customAnimate(el,fname,t,type){
	oB=tB=lB=tA=lA=lO=tO=0;oA=1;
	switch(fname){
		case 'OpacityIn': break;
		case 'OpacityOut' : oB=1;oA=0; break;
		case 'LeftToRightIn' : lB='-100%'; break;
		case 'TopToBottomIn' : tB='-100%'; break;
		case 'RightToLeftIn' : lB='100%'; break;
		case 'BottomToTopIn' : tB='100%'; break;
		case 'LeftToRightOut' : lA='100%'; break;
		case 'RightToLeftOut' : lA='-100%'; break;
		case 'BottomToTopOut' : tA='100%'; break;
		case 'TopToBottomOut' : tA='-100%'; break;
	}
	if(type=='in'){
		if(!$.browser.msie)el.show().transition({opacity:oB, top:tB, left:lB},0).stop(true,true).transition({opacity:oA, top:tA, left:lA}, t, 'ease');
		else el.show().animate({opacity:oB, top:tB, left:lB},0).stop(true,true).animate({opacity:oA, top:tA, left:lA}, t, 'ease');
	}
	else{
		if(!$.browser.msie)el.stop(true,true).transition({opacity:oA, top:tA, left:lA}, t, 'ease');
		else el.animate({opacity:oA, top:tA, left:lA}, t, 'ease');		
	}
}


/* ----------------------------------------------------- */
/* EOF */
/* ----------------------------------------------------- */

// init
$(document).ready(function(){
	
	if($('#slider2 li').size()>1){
		numSlide =$('#slider2 > ul > li').size()-1;
		min=0; max=numSlide;
		var curSlide=Math.floor(Math.random() * (max - min + 1)) + min;
		
		
		$('#slider2').append('<a class="slider2-navi prev" href="Prev"/><a class="slider2-navi next" href="Next"/>');
		$('#slider2 li:eq(0)').animate({opacity:1});
		var TimerSlider2;var TimerSliderClick;
		TimerSliderClick=setTimeout(function(){$('.slider2-navi.next').click()},0);
		$('.slider2-navi').click(function(){
			clearTimeout(TimerSlider2);
			clearTimeout(TimerSliderClick);
			thClick=this;
			TimerSliderClick= setTimeout(function(){$(thClick).click()},10000);
			t=500;
			$('#slider2 > ul > li').eq(curSlide).find('div:not(.s-bg)').each(function(index, element){
				inAnimation = $(this).attr('data-animation-in');
				t=t+100;
				customAnimate($(this),inAnimation+'Out',t,'out');
			});
			TimerSlider2 = setTimeout(function(){
				$('#slider2 li').eq(curSlide).fadeOut(300);
				$(this).hasClass('next') ? curSlide<numSlide ? curSlide++ : curSlide=0 : curSlide>0 ? curSlide-- : curSlide=numSlide;
				
				$('#slider2 li').eq(curSlide).stop(true,true).fadeIn(0);
				t=500;
				$('#slider2 li').eq(curSlide).find('div:not(.s-bg)').show().each(function(index, element){
					inAnimation = $(this).attr('data-animation-in');
					t=t+100;
					customAnimate($(this),inAnimation+'In',t,'in');
				});
				$('#slider2 li:not(:eq('+curSlide+')) div:not(.s-bg)').hide();			
			},400);
			return false;
		});
	}
});