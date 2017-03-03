$(document).ready(function() {
	$('ul.block-filtered-items li').each(function(index, element) {
		$(this).attr('data-type',$(this).attr('title')).attr('data-id','item'+index).removeAttr('title');
	});

  // get the action filter option item on page load
  var $filterType = $('#filter-cats a.active').attr('href');
	
  // get and assign the ourHolder element to the
	// $holder varible for use later
  var $holder = $('ul.block-filtered-items');

  // clone all items within the pre-assigned $holder element
  var $data =$holder.clone()

  // attempt to call Quicksand when a filter option
	// item is clicked
	$('#filter-cats a').click(function(e) {
		// reset the active class on all the buttons
		$('#filter-cats a').removeClass('active');
		
		// assign the class of the clicked filter option
		// element to our $filterType variable
		var $filterType = $(this).attr('href');
		$(this).addClass('active');
		
		if ($filterType == 'all') {
			// assign all li items to the $filteredData var when
			// the 'All' filter option is clicked
			var $filteredData = $data.find('li');
		} 
		else {
			// find all li elements that have our required $filterType
			// values for the data-type element
			var $filteredData = $data.find('li[data-type=' + $filterType + ']');
		}
		
		// call quicksand and assign transition parameters
		$holder.quicksand($filteredData, {
			duration: 800,
			easing: 'easeInOutQuad'
		},function(){$('.block-filtered-items').removeAttr('style');})
		
		return false;
	});
});